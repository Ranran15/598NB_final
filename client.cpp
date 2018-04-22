#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

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
};

struct plainQuery{
    BitMatrixRow row;
    ByteArray<KEYSIZE> r;
    ByteArray<KEYSIZE> b;
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


    return 0;
}