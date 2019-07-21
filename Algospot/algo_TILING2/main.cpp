#include <iostream>
#include <string.h>

using namespace std;

const int MOD = 1000000007;
int cache[101];


int go(int n){
    if(n<=1) return 1;
    int& ret=cache[n];
    if(ret!=-1) return ret;

    ret = (go(n-2)+go(n-1))%MOD;
    return ret;
}

int main() {
    int c;
    cin>>c;

    while(c--){
        int n;
        cin>>n;
        memset(cache, -1, sizeof(cache));
        cout<<go(n)<<endl;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}