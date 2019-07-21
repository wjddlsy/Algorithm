#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
int aMatch[1000], bMatch[1000];
bool visited[1000];
bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(auto b:adj[a]){
        if( bMatch[b]==-1 || dfs(bMatch[b])){
            aMatch[a]=b;
            bMatch[b]=a;
            return true;
        }
    }
    return false;
}
int bipartiteMatch(int n, int m){
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int ret=0;
    for(int i=0; i<n; ++i){
        if(aMatch[i]!=-1)
            continue;
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ret++;
    }
    return ret;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        adj=vector<vector<int>>(n);
        for(int i=0; i<m; ++i){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        cout<<bipartiteMatch(n, m)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}