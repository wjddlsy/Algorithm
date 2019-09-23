#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int profits[301][21], N, M;
int cache[21][301], back[21][301];

int solve(int here, int cur) {
    if(here==M)
        return 0;
    int &ret = cache[here][cur];
    if(ret!=-1)
        return ret;
    ret = 0;
    for(int i=0; i<=N; ++i) {
        if(cur-i<0)
            break;
        int tmp = solve(here+1, cur-i) + profits[i][here];
        if(tmp>ret) {
            back[here][cur] = i;
            ret = tmp;
        }
    }
    return ret;
}

//void reconstruct(int here, int cur, vector<int>& picked) {
//    if(here==M)
//        return;
//    for(int i=0; i<=N; ++i) {
//        if(cur-i<0)
//            break;
//        if( solve(here, cur) == solve(here+1, cur-i) + profits[i][here] ) {
//            picked[here] = i;
//            reconstruct(here+1, cur-i, picked);
//        }
//    }
//}

int main() {
    cin>>N>>M;
    for(int i=1; i<=N; ++i) {
        int money;
        cin>>money;
        for(int j=0; j<M; ++j) {
            cin>>profits[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, N)<<'\n';
    for(int i=0; i<M; ++i) {
        cout<<back[i][N]<<" ";
        N-=back[i][N];
    }
//    vector<int> ret(M);
//    reconstruct(0, N, ret);
//    for(int i : ret) {
//        cout<<i<<" ";
//    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}