#include <iostream>
#include <vector>
#include "cstring"
using namespace std;

const int INF=987654321;
int N, P;
int cost[16][16];
int cache[1<<17];

int solve(int status, int n){
    if(n>=P)
        return 0;
    int& ret=cache[status];
    if(ret!=-1)
        return ret;
    ret=INF;
    for(int i=0; i<N; ++i){
        if(status & (1<<i)){
            for(int j=0; j<N; ++j){
                if(i==j)
                    continue;
                if(!(status & (1<<j)))
                    ret=min(ret, solve(status | (1<<j), n+1)+cost[i][j]);
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>cost[i][j];
        }
    }
    int status=0, cnt=0;
    char c;
    for(int i=0; i<N; ++i){
        cin>>c;
        if(c=='Y'){
            status|=(1<<i);
            cnt++;
        }
    }
    cin>>P;
    int ret = solve(status, cnt);
    if (ret == INF)
        cout << -1 << '\n';
    else
        cout << ret<<'\n';

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}