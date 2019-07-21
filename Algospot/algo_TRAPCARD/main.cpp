#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;

int adj[1001][1001];

vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=1; b<=M; ++b){
        if(adj[a][b]){
            if(bMatch[b]==-1 || dfs(bMatch[b])){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch(){
    aMatch=vector<int>(N+1,-1);
    bMatch=vector<int>(M+1, -1);
    visited=vector<bool>(N+1, 0);
    int size=0;
    for(int start=1; start<=N; ++start){
        if(dfs(start))
            ++size;
    }
    return size;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        cin>>N>>M;
        memset(adj, 0, sizeof(adj));
        for(int i=1; i<=M; ++i){
            int a, b;
            cin>>a>>b;
            for(int j=a; j<=b; ++j){
                adj[j][i]=1;
            }
        }
        cout<<bipartiteMatch()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}