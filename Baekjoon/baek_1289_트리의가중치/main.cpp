#include <iostream>
#include <vector>
using namespace std;

const long long mod=1000000007;
int N;
vector<vector<pair<int,int>>> adj;
long long path[100001]; //root를 끝점으로하는 경로를 저장하기.

// 왼 오 루트 순회 post order
// 왼 * 오 하고 왼 오를 따로 저장해둔다음에 ....... 이게 되나 ,,,
// return 값 root를 끝 점으로 하는 경로의 길이 .....
long long postOrder(int root, int parent){
    if(adj[root].size()==1 && adj[root][0].first==parent){
        return 0;
    }

    vector<long long> temp_sum(adj[root].size(), 0);
    vector<long long> temp(adj[root].size(), 0);

    long long dist=0, dist2=0, child_num=0;
    for(int i=0; i<adj[root].size(); ++i){
        // 쭉 돌고
        if(adj[root][i].first!=parent) {
            long long tmp_dist=(adj[root][i].second * (1+postOrder(adj[root][i].first, root))%mod)%mod;
            dist = (dist + tmp_dist)%mod;
            if(child_num==0)
                temp_sum[child_num]=tmp_dist;
            else
                temp_sum[child_num] = (tmp_dist + temp_sum[child_num-1])%mod; //부분합
            temp[child_num] = tmp_dist; //각각 child-root
            child_num++;
        }
    }
    //root 끼고 도는 경로 합
    for(int i=0; i<child_num-1; ++i){
        dist2=(dist2+temp[i+1]*temp_sum[i])%mod;
    }
    path[root]=(dist2+dist)%mod;
    // root를 끝으로 하는 경로들이 나오는데
    // root를 끼고 도는 경로를 구하고
    //
    return dist%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    adj=vector<vector<pair<int,int>>>(N+1);
    for(int i=0; i<N-1; ++i){
        int A, B, W;
        cin>>A>>B>>W;
        adj[A].push_back({B, W});
        adj[B].push_back({A, W});
    }
    long long dist=0;
    postOrder(1, 0);
    for(int i=1; i<=N; ++i){
        dist=(dist+path[i])%mod;
    }
    cout << dist;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}