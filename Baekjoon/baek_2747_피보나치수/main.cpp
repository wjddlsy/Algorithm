#include <iostream>

using namespace std;

#define per 1500000

int mod=1000000;
int f[per]={0,1};
int main() {
    long long n;
    cin>>n;
    for(int i=2; i<per; ++i){
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
    }

    cout << f[n%per];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}