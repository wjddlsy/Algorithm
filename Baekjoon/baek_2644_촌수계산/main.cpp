#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
int discovered[101];

int bfs(int start, int end){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int here=q.front();
        q.pop();
        if(here==end)
            return discovered[here];
        for(auto there:adj[here]){
            if(!discovered[there]){
                discovered[there]=discovered[here]+1;
                q.push(there);
            }
        }
    }

    return -1;
}
int main() {
    int n, a, b, m;
    cin>>n>>a>>b>>m;
    adj=vector<vector<int>>(n+1);
    for(int i=0; i<m; ++i){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<bfs(a, b);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}