#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, S, M, V[101], cache[101][1001];
const int INF=987654321;
int solve(int n, int p) {
    if(p<0 || p>M)
        return -INF;
    if(n>N)
        return p;
    int &ret=cache[n][p];
    if(ret!=-1)
        return ret;
    ret = -INF;
    ret = max(ret, solve(n+1, p+V[n]));
    ret = max(ret, solve(n+1, p-V[n]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>S>>M;
    for(int i=1; i<=N; ++i) {
        cin>>V[i];
    }
    V[0] = 0;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, S);
    if(ret == -INF)
        cout<< - 1;
    else
        cout<< ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}