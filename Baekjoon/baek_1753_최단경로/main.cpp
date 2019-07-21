#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
const int INF=987654321;
vector<vector<pair<int, int>>> adj;

vector<int> dijikstra(){
    vector<int> ret(V, INF);
    ret[K]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(ret[here]<cost) continue;
        for(auto t:adj[here]){
            int there=t.first;
            int w=t.second;
            if(ret[there]>cost+w){
                ret[there]=cost+w;
                pq.push({-(cost+w), there});
            }
        }
    }
    return ret;
}

int main() {
    cin>>V>>E>>K;
    K--;
    adj.resize(V);
    for(int i=0; i<E; ++i){
        int u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    vector<int> ret=dijikstra();

    for(int i=0; i<V; ++i){
        if(ret[i]==INF)
            cout<<"INF"<<'\n';
        else
            cout<<ret[i]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}