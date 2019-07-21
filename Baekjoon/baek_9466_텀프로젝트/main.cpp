#include <iostream>
#include <vector>
using namespace std;

vector<int> adj;
vector<int> discovered, finished;
int counter;
int ret;
void dfs2(int here){
    discovered[here]=counter++;
    int there=adj[here];
    if(discovered[there]==-1)
        dfs2(there);
    //사이클
    else if(!finished[there]){
        for(int r=there; here!=r; r=adj[r])
            ret++;
        ret++;
    }
    finished[here]=true;
}

void dfsAll(int n){
    for(int here=1; here<=n; ++here){
        if(discovered[here]!=-1)
            continue;
        dfs2(here);

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        counter=0;
        ret=0;
        adj=vector<int>(n+1, 0);
        discovered=vector<int>(n+1, -1);
        finished=vector<int>(n+1, 0);
        for(int i=1; i<=n; ++i){
            cin>>adj[i];
        }
        dfsAll(n);
        cout<<n-ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}