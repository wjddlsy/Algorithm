#include <iostream>
#include <vector>
using namespace std;


int t[16], p[16];
int cache[16];
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin>>t[i]>>p[i];
    }

    cache[n]=(t[n]==1?p[n]:0);
    for(int i=n-1; i>0; --i) {
        int end = i + t[i]-1;
        if(end>n) {
            cache[i]=cache[i+1];
        }
        else {
            cache[i] = std::max(p[i] + cache[end+1], cache[i+1]);
        }

    }

    int max=0;
    for(int i=1; i<=n; ++i){
        max=std::max(cache[i], max);
    }

    cout << max;


}