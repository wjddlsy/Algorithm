#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long cache[100002][3];
int n;
vector<int> h[3];
long long dp(int index, int flag) {
    if(index==n)
        return 0;
    long long& ret=cache[index][flag];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0; i<=2; ++i) {
        if(i!=0 && i==flag)
            continue;
        ret=max(ret, dp(index+1, i)+h[i][index+1]);
    }
    return ret;
}
int main() {
    cin>>n;
    for(int i=0; i<3; ++i) {
        h[i]=vector<int>(n+1, 0);
    }
    for(int i=1; i<=n; ++i) {
        cin>>h[1][i];
    }
    for(int i=1; i<=n; ++i) {
        cin>>h[2][i];
    }
    memset(cache, -1, sizeof(cache));
    dp(0, 0);
    cout<<cache[0][0];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}