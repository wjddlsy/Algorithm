#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF=987654321;
int N, K, M, L;
int cache[10000][10];
vector<int> pre, semester;

int solve(int status, int n){
    if(__builtin_popcount(status)>=K)
        return 0;
    if(n==M)
        return INF;
    int &ret=cache[status][n];
    if(ret!=-1)
        return ret;
    ret=INF;
    int canTake = (semester[n] & ~status); // 이번 학기에 들을 수 있는 과목 중 아직 안들은 과목
    // 선수과목 다 안들은 것 거름
    for(int i=0; i<N; ++i){
        if((canTake & (1<<i)) && (status & pre[i]) !=pre[i]){
            canTake &= ~(1<<i);
        }
    }
    for(int take=canTake; take>0; take=((take-1)&canTake)){
        if(__builtin_popcount(take)>L) continue;
        ret=min(ret, solve(status | take , n+1)+1);
    }
    // 공집합
    ret=min(ret, solve(status, n+1));
    return ret;
}
int main() {
    int T = 0;
    cin >> T;
    while(T--){
        cin>>N>>K>>M>>L;
        memset(cache, -1, sizeof(cache));
        pre.clear();
        semester.clear();
        for(int i=0; i<N; ++i){
            int n;
            cin>>n;
            int status=0;
            for(int j=0; j<n; ++j){
                int a;
                cin>>a;
                status |=(1<<a);
            }
            pre.emplace_back(status);
        }
        for(int i=0; i<M; ++i){
            int n;
            cin>>n;
            int status=0;
            for(int j=0; j<n; ++j){
                int a;
                cin>>a;
                status |=(1<<a);
            }
            semester.emplace_back(status);
        }
        int ret=solve(0,0);
        if(ret==INF)
            cout<<"IMPOSSIBLE";
        else
            cout<<ret;
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}