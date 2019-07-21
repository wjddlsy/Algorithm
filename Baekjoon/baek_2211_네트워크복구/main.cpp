#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
const int INF=987654321;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(){
    priority_queue<pair<int, int>> pq;
    vector<int> dist(N, INF);
    pq.push({0, 0});
    dist[0]=0;
    vector<int> parent(N, -1);
    parent[0]=0;

    while(!pq.empty()){
        int here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[here]) {
            continue;
        }
        for(auto t:adj[here]){
            int there=t.first;
            int nextDist=t.second+cost;
            if(nextDist<dist[there]){
                dist[there]=nextDist;
                pq.push({-nextDist, there});
                parent[there]=here;
            }
        }
    }
    return parent;
}
int main() {
    cin>>N>>M;
    adj.resize(N);
    for(int i=0; i<M; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    // 다익스트라 고
    // 쓸데없는 회선 버리라는거자너
    vector<int> parent=dijkstra();

    int cnt=0;
    for(int i=0; i<N; ++i){
        if(parent[i]!=i && parent[i]!=-1)
            cnt++;
    }
    cout<<cnt<<'\n';
    for(int i=0; i<N; ++i){
        if(parent[i]!=i && parent[i]!=-1){
            cout<<i+1<<" "<<parent[i]+1<<'\n';
        }
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}