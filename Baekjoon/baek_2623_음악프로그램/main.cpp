#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void dfs(int here, const int& n){
    visited[here]=true;
    for(int there=1; there<=n; ++there){
        if(!visited[there] && adj[here][there])
            dfs(there, n);
    }
    order.push_back(here);
}
vector<int> topologicalSort(int n){
    for(int i=1; i<=n; ++i){
        if(!visited[i])
            dfs(i, n);
    }
    reverse(order.begin(), order.end());

    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}
int main() {
    int N, M;
    cin>>N>>M;
    adj=vector<vector<int>>(N+1, vector<int>(N+1, 0));
    visited=vector<bool>(N+1, false);
    for(int i=0; i<M; ++i){
        int n;
        cin>>n;
        int a=0, b=0;
        for(int i=1; i<=(n+1)/2; ++i){
            cin>>a;
            adj[b][a]=1;
            if(i*2>n)
                break;
            cin>>b;
            adj[a][b]=1;
        }
    }

    vector<int> ret=topologicalSort(N);
    if(ret.empty())
        cout<<0;
    else {
        for(auto o:ret)
            cout<<o<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}