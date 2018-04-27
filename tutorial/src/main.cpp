#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/relations/constraint_satisfaction_problems/r1cs/examples/r1cs_examples.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <openssl/aes.h>

using namespace libsnark;
using namespace std;
const size_t KEYSIZE = 16;
const int PLAIN_LENGTH = 140;  
const int TABLE_WIDTH = 1<<9;
const int TABLE_HEIGHT = 1<<8;
const int BOX_OVERHEAD = 16;

//plaintext length plus 2 public keys and 2 message digests
const int SLOT_LENGTH = PLAIN_LENGTH + 2*(KEYSIZE + BOX_OVERHEAD);


typedef unsigned char byte;
typedef byte BitMatrixRow[TABLE_WIDTH*SLOT_LENGTH];


struct serverInfo{
    int serverCount = 1;
};

template<size_t N>
class ByteArray{
    private:
        byte data[N];

    public:
        //constructor
        ByteArray(){
            memset(data,0,sizeof(data));
        }
        ByteArray(const ByteArray<N> & other){
            memmove(data,other.data,sizeof(data));
        }
        ByteArray(bool rand){
            if(rand){
                memset(data,0,sizeof(data));
                random();
            }
        }

        static const size_t size = N;

        //initialize random ByteArray
        void random(){
            for(int i=0;i<N;i++){
                data[i] = (byte) rand();
            }
        }

        void printArray(){
            cout<<"printArray:\n";
            for(int i=0;i<N;i++){
                cout<<data[i];
            }
            cout<<"\n";
        }

        byte* getData(){
            return data;
        }
};

byte* newKey(){
    ByteArray<KEYSIZE> k;
    k.random();
    return k.getData();
}

class Prf{
    private:
        AES_KEY enc_key;
        AES_KEY dec_key;
    public:
        Prf(){
            //byte randkey[KEYSIZE] = newKey();
            byte* k = newKey();
            AES_set_encrypt_key(k,128,&enc_key);
            AES_set_decrypt_key(k,128,&dec_key);
        }

        Prf( byte k[KEYSIZE]){
            AES_set_encrypt_key(k,128,&enc_key);
            AES_set_decrypt_key(k,128,&dec_key);
        }

        void encrypt(byte * msg, byte* enc_out){
            //byte enc_out[80];
            AES_encrypt(msg, enc_out, &enc_key);
            //return 
        }

        void decrypt(byte * enc_out, byte* dec_out){
            AES_decrypt(enc_out, dec_out, &dec_key);
        }
};
// ByteArray<KEYSIZE> * randomVectorKeys(){
//     ByteArray<KEYSIZE> s[TABLE_HEIGHT];
    
// }

struct plainQuery{
    BitMatrixRow row;

    //Array of booleans
    bool v[TABLE_HEIGHT];

    //array of random keys
    ByteArray<KEYSIZE> s[TABLE_HEIGHT];
};

struct location{
    int x =0;
    int y =0;
};

location calculateLocation(ByteArray<KEYSIZE> Kab, int Nab){
    location l;
    //p1 = PRF_Kab
    byte* chars;
    byte enc_out[256];

    int nab = Nab;
    chars = (byte*) &nab;
    //memcpy(chars,(char*)&Nab,sizeof(int));
    Prf p1(Kab.getData());

    p1.encrypt(chars,enc_out);
    //cout<<"encout: \n"<<enc_out<<endl;
    uint n = *(uint*)enc_out %(TABLE_HEIGHT*TABLE_WIDTH);//atoi((char*)enc_out);

    
    l.y = n/TABLE_WIDTH;
    l.x = n %TABLE_WIDTH;
    cout<<"LOCATION:"<<l.x<<" , "<<l.y<<endl;

    return l;
}


vector<plainQuery> genShare( location l, string msg, serverInfo si){
    cout<<"in genShare"<<endl;
    //TODO: 1. encrypt slot === encrypt msg


    //initialize 2 server
    plainQuery q1;

    //initialize v and s to random values
    for(int i =0; i<TABLE_HEIGHT;i++){
        q1.s[i] = ByteArray<KEYSIZE>();
        q1.s[i].random();

        q1.v[i] = (rand()%2 == 0);
    }




    plainQuery q2 = q1;
    //reset q2's v and s to only differ at row Index , y
    q2.v[l.y] =  !q1.v[l.y];
    q2.s[l.y] = ByteArray<KEYSIZE>(true);



    vector<plainQuery> queries;
    queries.push_back(q1);
    queries.push_back(q2);
    return queries;
}






/**
 * The code below provides an example of all stages of running a R1CS GG-ppzkSNARK.
 *
 * Of course, in a real-life scenario, we would have three distinct entities,
 * mangled into one in the demonstration below. The three entities are as follows.
 * (1) The "generator", which runs the ppzkSNARK generator on input a given
 *     constraint system CS to create a proving and a verification key for CS.
 * (2) The "prover", which runs the ppzkSNARK prover on input the proving key,
 *     a primary input for CS, and an auxiliary input for CS.
 * (3) The "verifier", which runs the ppzkSNARK verifier on input the verification key,
 *     a primary input for CS, and a proof.
 */
template<typename ppT>
bool run_r1cs_gg_ppzksnark(const r1cs_example<libff::Fr<ppT> > &example)
{
    libff::print_header("R1CS GG-ppzkSNARK Generator");
    r1cs_gg_ppzksnark_keypair<ppT> keypair = r1cs_gg_ppzksnark_generator<ppT>(example.constraint_system);
    printf("\n"); libff::print_indent(); libff::print_mem("after generator");

    libff::print_header("Preprocess verification key");
    r1cs_gg_ppzksnark_processed_verification_key<ppT> pvk = r1cs_gg_ppzksnark_verifier_process_vk<ppT>(keypair.vk);

    libff::print_header("R1CS GG-ppzkSNARK Prover");
    r1cs_gg_ppzksnark_proof<ppT> proof = r1cs_gg_ppzksnark_prover<ppT>(keypair.pk, example.primary_input, example.auxiliary_input);
    printf("\n"); libff::print_indent(); libff::print_mem("after prover");

    libff::print_header("R1CS GG-ppzkSNARK Verifier");
    const bool ans = r1cs_gg_ppzksnark_verifier_strong_IC<ppT>(keypair.vk, example.primary_input, proof);
    printf("\n"); libff::print_indent(); libff::print_mem("after verifier");
    printf("* The verification result is: %s\n", (ans ? "PASS" : "FAIL"));

    libff::print_header("R1CS GG-ppzkSNARK Online Verifier");
    const bool ans2 = r1cs_gg_ppzksnark_online_verifier_strong_IC<ppT>(pvk, example.primary_input, proof);
    assert(ans == ans2);

    return ans;
}

template<typename ppT>
void test_r1cs_gg_ppzksnark(size_t num_constraints, size_t input_size)
{
    r1cs_example<libff::Fr<ppT> > example = generate_r1cs_example_with_binary_input<libff::Fr<ppT> >(num_constraints, input_size);
    const bool bit = run_r1cs_gg_ppzksnark<ppT>(example);
    assert(bit);
}

int main () {
    default_r1cs_gg_ppzksnark_pp::init_public_params();
    test_r1cs_gg_ppzksnark<default_r1cs_gg_ppzksnark_pp>(1000, 100);

    ByteArray<KEYSIZE> a;// = new ByteArray<KEYSIZE>();
    a.random();
    a.printArray();
    cout<<"main"<<endl;
    serverInfo s;


    location l = calculateLocation(a,1);
    vector<plainQuery> queries = genShare(l,"msg",s);


    //AES encrypt/decrypt
    unsigned char text[] = "hello world";
    byte enc_out[80];
    byte dec_out[80];

    // AES_KEY enc_key, dec_key;
    // AES_set_encrypt_key(a.getData(),128,&enc_key);
    // AES_encrypt(text, enc_out, &enc_key);

    // AES_set_decrypt_key(a.getData(),128,&dec_key);
    // AES_decrypt(enc_out, dec_out, &dec_key);

    // cout<<"enc_out: "<<enc_out<<endl;
    // cout<<"dec_out: "<<dec_out<<endl;

    //test prf encode decode
    Prf f;
    Prf f2(a.getData());

    f2.encrypt(text,enc_out);
    f2.decrypt(enc_out,dec_out);
    cout<<dec_out<<endl;

    f.encrypt(text,enc_out);
    f.decrypt(enc_out,dec_out);
    cout<<dec_out<<endl;

    return 0;
}
