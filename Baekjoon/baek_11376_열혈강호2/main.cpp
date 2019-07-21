#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> adj[2000];
int aMatch[2000], bMatch[1000];
bool visited[2000];
bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(auto b:adj[a]){
            if(bMatch[b]==-1 || dfs(bMatch[b])){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
            }
    }
    return false;
}
int bipartiteMatch(){
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int size=0;
    for(int start=0; start<2*N; ++start){
        memset(visited, 0, sizeof(visited));
        if(dfs(start))
            ++size;
    }
    return size;
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i){
        int n;
        cin>>n;
        for(int j=0; j<n; ++j){
            int a;
            cin>>a;
            a--;
            adj[2*i].push_back(a);
            adj[2*i+1].push_back(a);
        }
    }
    printf("%d\n", bipartiteMatch());
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}