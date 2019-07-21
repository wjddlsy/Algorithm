#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
vector<vector<int>> adj;

vector<bool> visited;
int n;

void dfs(int here){
    if(visited[here])
        return;
    visited[here]=true;
    ++n;
    for(int i=0; i<adj[here].size(); ++i){
        dfs(adj[here][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    adj=vector<vector<int>>(N+1);
    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
    }

    priority_queue<pair<int, int>> pq;
    for(int i=1; i<=N; ++i){
        visited=vector<bool>(N, false);
        n=0;
        dfs(i);
        pq.push({n,-i});
    }

    while(!pq.empty()){
        int a, b, c, d;
        tie(a, b)=pq.top();
        pq.pop();
        tie(c, d)=pq.top();
        cout<<-b<<'\n';
        if(a!=c){
            break;
        }
        //cout<<d<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}