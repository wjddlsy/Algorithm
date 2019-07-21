#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool adj[1000][1000];
vector<int> aMatch, bMatch;
vector<bool> visited;
bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=0; b<M; ++b){
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
    aMatch=vector<int>(N, -1);
    bMatch=vector<int>(M, -1);
    int size=0;
    for(int start=0; start<N; ++start){
        visited=vector<bool>(N, false);
        if(dfs(start))
            ++size;
    }
    return size;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        int n;
        cin>>n;
        for(int j=0; j<n; ++j){
            int work;
            cin>>work;
            work--;
            adj[i][work]=true;
        }
    }
    cout<<bipartiteMatch();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}