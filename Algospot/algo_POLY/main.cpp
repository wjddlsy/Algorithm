#include <iostream>
#include <string.h>
using namespace std;
int cache[101][101];
const int MOD=10000000;

int poly(int n, int first){
    if(n==first)
        return 1;
    int& ret=cache[n][first];
    if(ret!=-1) return ret;
    ret=0;

    for(int second=1; second<=n-first; ++second){
        int add=second+first-1;
        add=(add*poly(n-first, second))%MOD;
        ret=(ret+add)%MOD;
    }

    return ret;

}

int main() {
    int c;
    cin>>c;
    while(c--){
        int ret=0;
        int n;
        cin>>n;
        memset(cache, -1, sizeof(cache));
        for(int i=1; i<=n; ++i){
            ret+=poly(n, i);
            ret%=MOD;
        }
        cout<<ret<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}