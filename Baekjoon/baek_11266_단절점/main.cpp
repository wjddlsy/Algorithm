#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100001

vector<vector<int>> adj;
int discovered[MAX], isCutVertex[MAX], counter=0;

int findCutVertex(int here, bool isRoot){
    discovered[here]=counter++;
    int ret=discovered[here];
    int children=0;
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
        if(discovered[there]==-1){
            ++children;
            int subtree=findCutVertex(there ,false);
            if(!isRoot && subtree>=discovered[here]) {
                isCutVertex[here] = true;
            }
            ret=min(ret, subtree);
        }
        else
            ret=min(ret, discovered[there]);
    }
    if(isRoot) isCutVertex[here]=(children>=2);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin>>V>>E;
    adj=vector<vector<int>>(V);
    memset(discovered, -1, sizeof(discovered));

    for(int i=0; i<E; ++i){
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for(int i=0; i<V; ++i){
        if(discovered[i]==-1)
            findCutVertex(i, 1);
    }

    int cnt=0;
    for (int i = 0; i < V; ++i) {
        if (isCutVertex[i])
            cnt++;
    }
    cout<<cnt<<'\n';
    for(int i=0; i<V; ++i){
        if(isCutVertex[i])
            cout<<i+1<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}