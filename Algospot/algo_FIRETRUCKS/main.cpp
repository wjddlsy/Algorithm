#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> fires, fireStations;

int V, E, n, m;

int dijkstra(int src){
    int ret=0;
    priority_queue<pair<int, int>> pq;
    vector<int> dist(V+1, 987654321);
    pq.push({0, src});
    dist[src]=0;
    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        for(auto t:adj[here]){
            int there=t.first;
            int nextDist=cost+t.second;
            if(dist[there]>nextDist){
                dist[there]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }

    for(auto f:fires){
        ret+=dist[f];
    }
    return ret;
}
int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>V>>E>>n>>m;
        adj.clear();
        adj.resize(V+1);
        for(int i=0; i<E; ++i){
            int a, b, t;
            cin>>a>>b>>t;
            a--; b--;
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});

        }
        fires.clear();

        for(int i=0; i<n; ++i){
            int a;
            cin>>a;
            a--;
            fires.push_back(a);
        }
        for(int i=0; i<m; ++i){
            int a;
            cin>>a;
            a--;
            adj[V].push_back({a, 0});
            adj[0].push_back({V, 0});
        }
        cout<<dijkstra(V)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}