#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, S, E;
const int INF=987654321;
vector<vector<pair<int, int>>> adj;

int dijikstra(){
    vector<int> dist(N+1, INF);
    dist[S]=0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int here=pq.top().second;
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

    return dist[E];
}
int main() {
    cin>>N>>M;
    adj.resize(N+1);
    for(int i=0; i<M; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    cin>>S>>E;
    cout<<dijikstra();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}