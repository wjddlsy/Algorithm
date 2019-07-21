#include <iostream>
#include <vector>
using namespace std;

vector<int> adj;
vector<bool> visited;

int checkCycle=0;
void dfs(int start, int here){
    if(visited[here]) {
        if(here==start)
            checkCycle=1;
        return;
    }
    visited[here]=true;
    dfs(start, adj[here]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while (T--){
        int N;
        cin>>N;
        adj=vector<int>(N+1);
        visited=vector<bool>(N+1, false);
        for(int i=1; i<=N; ++i){
            cin>>adj[i];
        }
        int ret=0;
        for(int i=1; i<=N; ++i){
            if(visited[i])
                continue;
            checkCycle=0;
            dfs(i,i);
            ret+=checkCycle;

        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}