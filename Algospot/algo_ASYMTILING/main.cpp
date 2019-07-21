#include <iostream>
#include <string.h>
using namespace std;

const int MOD=1000000007;
int n;
int cache[101];
int cache2[101];
int tile(int t){
    if(t<=1)
        return 1;
    int& ret=cache[t];
    if(ret!=-1)
        return ret;
    return ret=(tile(t-2)+tile(t-1))%MOD;
}

int tile2(int t){
    if(t<=2) return 0;
    int& ret=cache2[t];
    if(ret!=-1) return ret;
    ret=tile2(t-2)%MOD;
    ret=(ret+tile2(t-4))%MOD;
    ret=(ret+tile(t-3))%MOD;
    ret=(ret+tile(t-3))%MOD;
    return ret;
}

int main() {
    int c;
    cin>>c;
    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));
    while(c--){
        //int n;
        cin>>n;
        cout<<tile2(n)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}