#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321


int N, first, last, ret=0;
vector<vector<pair<int,int>>> adj;
vector<bool> visited;
void dfs(int here, int dist, int max_val){
    if(here==last) {
        ret=dist-max_val;
        return;
    }
    visited[here]=true;
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i].first;
        int cost=adj[here][i].second;
        max_val=max(max_val, cost);
        if(!visited[there]){
            dfs(there, dist+cost, max_val);
        }
    }
}

void bfs(int start){
    vector<bool> discovered(adj.size(), false);
    queue<pair<int, pair<int, int>>> q;
    discovered[start]=true;
    q.push({start,{0,0}});
    while(!q.empty()){
        int here=q.front().first;
        int dist=q.front().second.first;
        int max_val=q.front().second.second;
        if(here==last){
            ret=dist-max_val;
            return;
        }
        q.pop();
        for(int i=0; i<adj[here].size(); ++i){
            int there=adj[here][i].first;
            int cost=adj[here][i].second;
            if(!discovered[there]){
                q.push({there,{dist+cost, max(max_val, cost)}});
                discovered[there]=true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>first>>last;
    first--; last--;
    adj=vector<vector<pair<int,int>>>(N);
    visited=vector<bool>(N, false);
    for(int i=0; i<N-1; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
        adj[b-1].push_back({a-1,c});
    }
    bfs(first);
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}