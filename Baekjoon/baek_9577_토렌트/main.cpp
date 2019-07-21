#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int adj[101][101];
vector<int> aMatch, bMatch, visited;


int n, m;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=1; b<=n; ++b){
        if(adj[a][b])
            if(bMatch[b]==-1 || dfs(bMatch[b])){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
            }
    }
    return false;
}
int bipartiteMatch(){
    aMatch=vector<int>(101, -1);
    bMatch=vector<int>(n+1, -1);
    int size=0;
    for(int start=1; start<=100; ++start){
        visited=vector<int>(101, 0);
        if(dfs(start))
            ++size;
        if(size==n)
            return start;
    }
    return -1;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(adj, 0, sizeof(adj));
        for(int i=0; i<m; ++i){
            int t1, t2, a;
            cin>>t1>>t2>>a;
            for(int j=0; j<a; ++j){
                int q;
                cin>>q;
                for(int k=t1+1; k<=t2; ++k){
                    adj[k][q]=1;
                }

            }
        }
        cout<<bipartiteMatch()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}