#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <openssl/aes.h>

#include <libsnark/gadgetlib1/gadgets/basic_gadgets.hpp>
#include <libsnark/gadgetlib1/gadgets/hashes/sha256/sha256_gadget.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_ppzksnark/r1cs_ppzksnark.hpp>
//#include <libsnark/zk_proof_systems/ppzksnark/bacs_ppzksnark/bacs_ppzksnark.hpp>
//
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






int main(){
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