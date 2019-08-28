#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int INF=987654321;

int cache[10001], visited[10001], cnt=0;
vector<vector<pair<int, int>>> adj;
void dfs(int here) {
    for(auto &v:adj[here]) {
        int there=v.first, cost=v.second;
        if(!cache[there]) dfs(there);
        if(cache[there]+cost>cache[here])
            cache[here]=cache[there]+cost;
    }
}

void dfs2(int here) {
    if(visited[here])
        return;
    visited[here]=true;
    for(auto &v:adj[here]) {
        int there=v.first, cost=v.second;
        if(cache[there]+cost==cache[here]) {
            dfs2(there);
            cnt++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, src, tgt;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0; i<m; ++i) {
        int u, v, cost;
        cin>>u>>v>>cost;
        u--; v--;
        adj[u].emplace_back(v, cost);
    }
    cin>>src>>tgt;
    src--; tgt--;
    dfs(src);
    dfs2(src);
    cout<<cache[src]<<" "<<cnt;
    return 0;
}