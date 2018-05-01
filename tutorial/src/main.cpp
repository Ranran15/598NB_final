#include <libff/common/default_types/ec_pp.hpp>
#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/relations/constraint_satisfaction_problems/r1cs/examples/r1cs_examples.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>
#include "libsnark/common/default_types/r1cs_ppzksnark_pp.hpp"
#include "libsnark/gadgetlib1/gadgets/basic_gadgets.hpp"
#include "libsnark/zk_proof_systems/ppzksnark/r1cs_ppzksnark/r1cs_ppzksnark.hpp"

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <openssl/aes.h>
#include <openssl/sha.h>

using namespace libsnark;
using namespace std;
const size_t KEYSIZE = 16;
const int PLAIN_LENGTH = 140;  
const int TABLE_WIDTH = 1<<9;
const int TABLE_HEIGHT = 1<<8;
const int BOX_OVERHEAD = 16;

const int WALLET_LENGTH = 128;


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

        byte & operator[](size_t i){
            if(i>=N)
                throw out_of_range("ByteArray::[] out of range");
            return data[i];
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

        size_t getSize(){
            return N;
        }
        long toLong(){
            return *(long*)data;
        }

        void setWithLong(long i){
            memcpy(data, (char*)&i, sizeof(long));
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
    BitMatrixRow v;

    //Array of booleans
    //bool b[TABLE_HEIGHT];
    int b[TABLE_HEIGHT];

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

        q1.b[i] = (rand()%2 == 0);
        //q1.v = 
    }

    ByteArray<KEYSIZE> s_star[TABLE_HEIGHT] = ByteArray<KEYSIZE>(true);
    //s_star.random();



    plainQuery q2 = q1;
    //2 server method
    //reset q2's v and s to only differ at row Index , y
    //q2.b[l.y] =  !q1.b[l.y];
    //q2.s[l.y] = ByteArray<KEYSIZE>(true);

    //N-server method:
    //sum of bi = elx
    //sum of si = s* * elx
    for(int i=0;i<TABLE_HEIGHT;i++){
        if(i==l.y){
            q2.b[i] = 1-q1.b[l.y];
            q2.s[i].setWithLong(s_star[i].toLong() - q1.s[l.y].toLong());
        }else{
            q2.b[i] = 0-q1.b[i];
            q2.s[i].setWithLong(0 - q1.s[i].toLong());
            // if(q1.b[i]+q2.b[i]!=0){
            //     cout<<"something wrong at index "<<i<<endl;
            //     cout<<"q1.b[i] "<<q1.b[i]<<endl;
            // }
            // if(q1.s[i].toLong()+q2.s[i].toLong()!=0){
            //     cout<<"something wrong at index "<<i<<endl;
            //     cout<<"q1.s[i] "<<q1.s[i].toLong()<<endl;
            // }
            //cout<<"should be 0:"<<(q1.b[i]+q2.b[i]);
        }
    }


    cout<<"l.y: "<<l.y<<endl;
    cout<<"==========================="<<endl;
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

// int main () {
//     default_r1cs_gg_ppzksnark_pp::init_public_params();
//     test_r1cs_gg_ppzksnark<default_r1cs_gg_ppzksnark_pp>(1000, 100);

//     ByteArray<KEYSIZE> a;// = new ByteArray<KEYSIZE>();
//     a.random();
//     a.printArray();
//     cout<<"main"<<endl;
//     serverInfo s;


//     location l = calculateLocation(a,1);
//     vector<plainQuery> queries = genShare(l,"msg",s);


//     //AES encrypt/decrypt
//     unsigned char text[] = "hello world";
//     byte enc_out[80];
//     byte dec_out[80];

//     // AES_KEY enc_key, dec_key;
//     // AES_set_encrypt_key(a.getData(),128,&enc_key);
//     // AES_encrypt(text, enc_out, &enc_key);

//     // AES_set_decrypt_key(a.getData(),128,&dec_key);
//     // AES_decrypt(enc_out, dec_out, &dec_key);

//     // cout<<"enc_out: "<<enc_out<<endl;
//     // cout<<"dec_out: "<<dec_out<<endl;

//     //test prf encode decode
//     Prf f;
//     Prf f2(a.getData());

//     f2.encrypt(text,enc_out);
//     f2.decrypt(enc_out,dec_out);
//     cout<<dec_out<<endl;

//     f.encrypt(text,enc_out);
//     f.decrypt(enc_out,dec_out);
//     cout<<dec_out<<endl;

//     return 0;
// }
struct wallet
{
    char* id = new char[65];
    int balance;    
};
const int CLIENT_ID_LENGTH = WALLET_LENGTH/2;
//typedef ByteArray<CLIENT_ID_LENGTH> clientId;


void sha256(char *string, char outputBuffer[65])
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}
//This should use a trusted 3rd party to issue credential
wallet regWallet(char* id){
    wallet w;
    sha256(id,w.id);
    w.balance=1;
    return w;
}

bool verifyWallet(char* hash1, char* hash2){
    return strcmp(hash1, hash2) == 0;
}
//This signing process should be implemented with zk
//Here is just a simple demo without zk
bool signWallet(wallet w){
    char* client_ip = "127.0.0.1";

    char* hash = new char[65];
    sha256(client_ip,hash);

    bool result = verifyWallet(w.id, hash);

    delete[] hash;
    //reject or process
    return result;

}

struct commitments
{
    vector<vector<long long>> ss;
    //vector<long> c2;
    vector<vector<long long>> bs;

    //vector<long> c3,c4;
};

long long computeCommitment(long g, long x, long h, long r, long p){
    return (long long)((long long)pow(g,r) * (long long)pow(h,x))%p; //% p;
}

//Generate Pedersen Commitment
commitments Pedersen(vector<plainQuery> & query){
    ByteArray<KEYSIZE> s1[TABLE_HEIGHT] = query[0].s;
    ByteArray<KEYSIZE> s2[TABLE_HEIGHT] = query[1].s;

    auto b1 = query[0].b;
    auto b2 = query[1].b;

    //primes
    // long p  = 1301081;
    // long g,h = 1300051, 1299743;
    // long r = 1299721;

    long p  = 1109;
    long q = 277;
    //long g = 966;
    long r = 29;//75;

    long g1 = 127; //g
    long h = 29; //v

    //TODO: x should loop through s and b
    //long x = 30;
    commitments c;
    vector<long long> c1,c2,c3,c4;
    c.ss.push_back(c1);
    c.ss.push_back(c2);
    c.bs.push_back(c3);
    c.bs.push_back(c4);
    for(int i=0;i<TABLE_HEIGHT;i++){
        long x = s1[i].toLong();
        long x2 = s2[i].toLong();


        c.ss[0].push_back(computeCommitment(g1,x,h,r,p)); 
        c.ss[1].push_back(computeCommitment(g1,x2,h,r,p));

        if(i==0){
            cout<<"ss[10]"<<computeCommitment(g1,x,h,r,p)<<endl;
            //cout<<"inputs: "<<g<<" "<<x<<" "<<h<<" "<<r<<" "<<p<<" "<<s1[i]<<endl;
        }

        long x3 = (long) b1[i];
        long x4 = (long) b2[i];

        
        long long cc3=computeCommitment(g1,x3,h,r,p);
        long long cc4 = computeCommitment(g1,x4,h,r,p);
        if(x3+x4==1){
	    cout<<"b1:"<<x3<<", b2:"<<x4<<endl;
            cout<<"at i="<<i<<": b1+b2="<<x3+x4<<endl;
            cout<<"sumB: cc3+cc4 = "<<cc3+cc4<<endl;
            cout<<"commitment of 1: "<<computeCommitment(g1,1,h,r+r,p)<<endl;
        }
        else{
	    cout<<"b1:"<<x3<<", b2:"<<x4<<endl;
            cout<<"at "<<i<<" : b1+b2="<<x3+x4<<endl;
            cout<<"Sumb: cc3+cc4 = "<<cc3+cc4<<endl;
            cout<<"commitment of 0: "<<computeCommitment(g1,0,h,r+r,p)<<endl;
        }
        c.bs[0].push_back(cc3); 
        c.bs[1].push_back(cc4);
    }

    //long c = ((long)pow(g,x) * (long)pow(h,r)) % p;



    //commitment m = g^r * h^m
    //vector<long>
    return c;
}

bool verifyPederson(commitments & cc, plainQuery & query, int server_idx){
    long p  = 1109;
    long q = 277;
    //long g = 966;
    long r = 29;//75;


    long g1 = 127;
    long h = 29;
    //long x = 30;
    vector<long> Bsum, Ssum;
    ByteArray<KEYSIZE> s[TABLE_HEIGHT] = query.s;
    auto b = query.b;
    //verify it's correct commitment to server_idx
    for(size_t i=0;i<TABLE_HEIGHT;i++){
        long x = s[i].toLong();
        long x3 = (long) b[i];

        if(cc.ss[server_idx][i]!=computeCommitment(g1,x,h,r,p)){
            //cout<<"inputs: "<<g<<" "<<x<<" "<<h<<" "<<r<<" "<<p<<" "<<s[i]<<endl;
            cout<<"commitment not equal!!!!!\n"<<"i:"<<i<<";\n values:\n ss[idx][i]:"<<cc.ss[server_idx][i]<<"\ncomputed:"<<computeCommitment(g1,x,h,r,p)<<endl;
            //cout<<"inputs: "<<g<<" "<<x<<" "<<h<<" "<<r<<" "<<p<<" "<<s[i]<<endl;
            return false;
        }
        if(cc.bs[server_idx][i]!=computeCommitment(g1,x3,h,r,p)){
            cout<<"commitment not equal!!!!!\n"<<"i:"<<i<<";\n values:\nbs[idx][i]:"<<cc.bs[server_idx][i]<<"\ncomputed:"<<computeCommitment(g1,x,h,r,p)<<endl;
            return false;
        }

        Bsum.push_back(cc.ss[0][i]+cc.ss[1][i]);
        Ssum.push_back(cc.bs[0][i]+cc.bs[1][i]);
        if(i==65)
         cout<<"sumB at index "<<i<<": "<<cc.ss[0][i]+cc.ss[1][i]<<endl;
        // //cout<<"sumS at index "<<i<<": "<<cc.bs[0][i]+cc.bs[1][i]<<endl;
        // long zz = computeCommitment(g,0,h,r,p);
        // cout<<"commitment to zero: "<<zz<<endl;
    }


    return true;
}


int main() {
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

    //test prf encode decode
    Prf f;
    Prf f2(a.getData());

    f2.encrypt(text,enc_out);
    f2.decrypt(enc_out,dec_out);
    cout<<dec_out<<endl;

    f.encrypt(text,enc_out);
    f.decrypt(enc_out,dec_out);
    cout<<dec_out<<endl;



    char* id = "127.0.0.1";
    wallet w = regWallet(id);

    cout<<w.balance<<", "<<w.id<<endl;
    bool r = signWallet(w);
    cout<<"signwallet: "<<r<<endl;

    //long commitment = Pedersen(queries);

    commitments c = Pedersen(queries);
    bool r2 = verifyPederson(c,queries[0],0);
    cout<<r2<<endl;

    bool r3 = verifyPederson(c,queries[1],1);
    cout<<r3<<endl;







  return 0;
}
