#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> order;
vector<int> visited;
int n;
void dfs(int here){
    visited[here]=true;
    for(int i=1; i<=n; ++i){
        if(adj[here][i] && !visited[i])
            dfs(i);
    }
    order.push_back(here);
}

vector<int> topologicalSort(){
    for(int i=1; i<=n; ++i){
        if(visited[i])
            continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j)
            if(adj[order[j]][order[i]])
                return vector<int>();
    }
    return order;

}
int main() {
    int t;
    cin>>t;
    while(t--){
        //int n;
        cin>>n;
        vector<int> input(n+1);
        adj=vector<vector<int>>(n+1, vector<int>(n+1,0));
        visited=vector<int>(n+1, 0);
        order.clear();
        for(int i=1; i<=n; ++i){
            cin>>input[i];
        }
        for(int i=1; i<=n; ++i){
            for(int j=i+1; j<=n; ++j){
                adj[input[i]][input[j]]=1;
            }
        }
        int m;
        cin>>m;
        for(int i=1; i<=m; ++i){
            int a, b;
            cin>>a>>b;
            swap(adj[a][b], adj[b][a]);
        }
        vector<int> ret=topologicalSort();
        if(ret.empty())
            cout<<"IMPOSSIBLE";
        else{
            for(int i=0; i<n; ++i){
                cout<<order[i]<<" ";
            }
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}