#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <openssl/aes.h>

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

struct plainQuery{
    BitMatrixRow row;

    //Array of booleans
    bool v[TABLE_HEIGHT];

    //array of random keys
    ByteArray<KEYSIZE> s[TABLE_HEIGHT];
};

vector<plainQuery> genShare(ByteArray<KEYSIZE> Kab, int Nab, string msg, serverInfo si){
    cout<<"in genShare"<<endl;
    vector<plainQuery> queries;
    return queries;
}




int main(){
    ByteArray<KEYSIZE> a;// = new ByteArray<KEYSIZE>();
    a.random();
    a.printArray();
    cout<<"main"<<endl;
    serverInfo s;
    vector<plainQuery> queries = genShare(a,1,"msg",s);


    //AES encrypt/decrypt
    unsigned char text[] = "hello world";
    byte enc_out[80];
    byte dec_out[80];

    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(a.getData(),128,&enc_key);
    AES_encrypt(text, enc_out, &enc_key);

    AES_set_decrypt_key(a.getData(),128,&dec_key);
    AES_decrypt(enc_out, dec_out, &dec_key);

    cout<<"enc_out: "<<enc_out<<endl;
    cout<<"dec_out: "<<dec_out<<endl;

    return 0;
}