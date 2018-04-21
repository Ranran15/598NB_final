#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const size_t KEYSIZE = 16;

typedef unsigned char byte;


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


void genShare(ByteArray<KEYSIZE> Kab, int Nab, string msg, serverInfo si){
    cout<<"in genShare"<<endl;
}


int main(){
    ByteArray<KEYSIZE> a;// = new ByteArray<KEYSIZE>();
    a.random();
    a.printArray();
    cout<<"main"<<endl;
    serverInfo s;
    genShare(a,1,"msg",s);
    return 0;
}