#include <iostream>
#include <vector>
#include <queue>
#include <float.h>
using namespace std;

int N, M;
vector<vector<pair<int, double>>> adj;

double dijkstra(){
    vector<double> dist(N, DBL_MAX);
    priority_queue<pair<double, int>> pq;
    pq.push({-1.0, 0});
    dist[0]=1;
    while(!pq.empty()){
        double cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        for(auto t:adj[here]){
            int there=t.first;
            double nextDist=cost*t.second;
            if(dist[there]>nextDist){
                dist[there]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist[N-1];
}
int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>N>>M;
        adj=vector<vector<pair<int, double>>>(N);
        for(int i=0; i<M; ++i){
            int a, b;
            double c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        printf("%.10f\n", dijkstra());
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}