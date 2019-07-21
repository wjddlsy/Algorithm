#include <iostream>
#include <string.h>

#define div 10000007
using namespace std;


long long cache[101][101];
long long nCk(int n, int k){

    if(k==0 || n==k) return 1;
    if(cache[n][k]!=-1) return cache[n][k];
    return cache[n][k]=(nCk(n-1, k-1)+nCk(n-1, k));

}

int main() {
    int n,k;
    cin>>n>>k;
    memset(cache, -1, sizeof(cache));

    cout <<nCk(n,k);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}