#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
         int N;
         cin>>N;
         long long cache[101]={};
         cache[1]=cache[2]=cache[3]=1;
         cache[4]=cache[5]=2;
         cache[6]=3;
         for(int i=7; i<=N; ++i) {
             cache[i]=cache[i-1]+cache[i-5];
         }
         cout<<cache[N]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}