#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF=200000000;
vector<vector<pair<int, int>>> adj;
int N, E;


int dijkstra(int src, int dest){
    priority_queue<pair<int, int>> pq;
    vector<int> dist(N, INF);
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[here]<cost)
            continue;
        for(auto t:adj[here]){
            int there=t.first;
            int nextDist=t.second+cost;
            if(dist[there]>nextDist){
                dist[there]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist[dest];
}

int main() {
    cin>>N>>E;
    adj.resize(N);
    int a, b, c;
    for(int i=0; i<E; ++i){
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1, c});
        adj[b-1].push_back({a-1, c});
    }
    cin>>a>>b;
    a--; b--;
    int AtoB=dijkstra(a, b);
    int toA=dijkstra(0, a);
    int toB=dijkstra(0, b);
    int Bto=dijkstra(b, N-1);
    int Ato=dijkstra(a, N-1);

    int f=toA+AtoB+Bto;
    int s=toB+AtoB+Ato;

    int dist=min(f, s);
    if(dist>INF)
        cout<<-1;
    else
        cout<<dist;
    return 0;
}