#include <iostream>
#include <string.h>

using namespace std;

int cache[10001];
int wine[10001];
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i){
        int in;
        cin>>in;
        wine[i]=in;
    }
    cache[1]=wine[1];
    cache[2]=wine[1]+wine[2];
    for(int i=3; i<=n; ++i){
        int ret=0;
        ret=std::max(wine[i]+cache[i-2], cache[i-1]);
        ret=std::max(ret, wine[i]+wine[i-1]+cache[i-3]);
        cache[i]=ret;
    }
    cout<<cache[n];

    return 0;
}