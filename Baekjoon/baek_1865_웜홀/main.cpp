#include <iostream>
#include <vector>

using namespace std;

const int INF=987654321;
int N, M, W;
vector<vector<pair<int, int>>> adj;

string bellmanford(){
    vector<int> upper(N, INF);
    upper[0]=0;
    bool update;
    for(int k=0; k<N; ++k){
        update=false;
        for(int here=0; here<N; ++here){
            for(auto t:adj[here]){
                int there=t.first;
                int cost=t.second;
                if(upper[there]>upper[here]+cost){
                    upper[there]=upper[here]+cost;
                    update=true;
                }
            }
        }
        if(!update)
            break;
    }
    if(update) return "YES";
    return "NO";

}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>N>>M>>W;
        adj.clear();
        adj.resize(N);
        for(int i=0; i<M; ++i){
            int S, E, T;
            cin>>S>>E>>T;
            S--; E--;
            adj[S].push_back({E, T});
            adj[E].push_back({S, T});
        }
        for(int i=0; i<W; ++i){
            int S, E, T;
            cin>>S>>E>>T;
            S--; E--;
            adj[S].push_back({E, -T});
        }
        cout<<bellmanford()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}