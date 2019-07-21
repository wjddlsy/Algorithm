#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> adj;
bool visited[4000];
int n, ret=987654321;

void dfs(int here, vector<int>& musk, int parent) {
    if(musk.size()==3) {
        return;
    }
    visited[here]=true;
    for(auto &there:adj[here]) {
        if(there==parent && musk.size()==2) {
            int sum=0;
            musk.emplace_back(parent);
            for(auto &m:musk) {
                sum+=adj[m].size()-2;
            }
            ret=min(ret, sum);
            return;
        }
        if(visited[there])
            continue;
        musk.emplace_back(there);
        dfs(there, musk, parent);
        musk.pop_back();
    }
}

void dfsAll(){
    for(int i=0; i<n; ++i){
        memset(visited, 0, sizeof(visited));
        vector<int> musk;
        //musk.emplace_back(i);
        dfs(i, musk, i);
    }
}
int main() {
    int m;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0; i<m; ++i){
        int u, v; cin>>u>>v;
        u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfsAll();
    if(ret==987654321)
        cout<<-1;
    else
        cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}