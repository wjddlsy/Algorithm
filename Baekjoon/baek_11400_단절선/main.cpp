#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100000

vector<int> adj[MAX];
int discovered[MAX], counter=0;
vector<pair<int, int>> cutEdges;
int findCutEdge(int here, int parent){
    discovered[here]=counter++;
    int ret=discovered[here];
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
        if(there==parent)
            continue;
        if(discovered[there]==-1){
            int subtree=findCutEdge(there, here);
            if(subtree>discovered[here]){
                if(here>there)
                    cutEdges.emplace_back(make_pair(there, here));
                else
                    cutEdges.emplace_back(make_pair(here, there));
            }
            ret=min(ret, subtree);
        }
        else
            ret=min(ret, discovered[there]);
    }
    return ret;

}
int main() {
    int V, E;
    cin>>V>>E;
    memset(discovered, -1, sizeof(discovered));
    for(int i=0; i<E; ++i){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findCutEdge(0, 0);
    sort(cutEdges.begin(), cutEdges.end());
    cout<<cutEdges.size()<<'\n' ;
    for(auto p:cutEdges){
        cout<<p.first+1<<" "<<p.second+1<<'\n';
    }

    //td::cout << "Hello, World!" << std::endl;
    return 0;
}