#include <iostream>
#include <cstring>

using namespace std;

const long long MOD = 1000000007;
long long cache[101][101][101];

long long solve(int n, int l, int r) {
    if(n==0)
        return 0;
    if(l==0 || r==0)
        return 0;
    if(n==1) {
        if(l==1 && r==1)
            return 1;
        else
            return 0;
    }
    long long &ret=cache[n][l][r];
    if(ret!=-1)
        return ret;
    ret = 0;
    ret = (ret +  solve(n-1,l, r) * (n-2) + solve(n-1, l-1, r) + solve(n-1, l, r-1))%MOD;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L, R;
    cin>>N>>L>>R;
    memset(cache, -1, sizeof(cache));
    cout<<solve(N, L, R);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}