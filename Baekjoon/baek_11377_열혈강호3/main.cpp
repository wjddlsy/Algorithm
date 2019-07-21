#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, K;

vector<int> adj[1000];
int aMatch[1000], bMatch[1000];
bool visited[1000];
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
int bipartiteMatch(int k){
    int size=0;
    for(int start=0; start<N; ++start){
        memset(visited, 0, sizeof(visited));
        if(dfs(start))
            ++size;
        if(size>=k)
            break;
    }
    return size;
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0; i<N; ++i){
        int n;
        cin>>n;
        for(int j=0; j<n; ++j){
            int a;
            cin>>a;
            a--;
            adj[i].push_back(a);
        }
    }
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int ret=0;
    ret+=bipartiteMatch(N);
    ret+=bipartiteMatch(K);
    printf("%d\n", ret);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}