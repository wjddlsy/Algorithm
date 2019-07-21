#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void dfs(int here){
    visited[here]=true;
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
        if(!visited[there])
            dfs(there);
    }
    order.push_back(here);
}

void dfsAll(){
    for(int i=1; i<adj.size(); ++i){
        if(visited[i])
            continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());
}
int main() {
    int N, M;
    cin>>N>>M;
    adj=vector<vector<int>>(N+1);
    visited=vector<bool>(N+1, false);
    order.clear();
    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfsAll();

    for(auto a:order){
        cout<<a<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}