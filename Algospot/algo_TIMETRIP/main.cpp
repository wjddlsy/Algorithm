#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<pair<int, int>>> adj;

#define INF 987654321
int G, W;

bool reachable[100][100];

int bellmanFord(int src, int target){
    for(int k=0; k<G; ++k){
        for(int i=0; i<G; ++i){
            for(int j=0; j<G; ++j){
                reachable[i][j]|=reachable[i][k] && reachable[k][j];
            }
        }
    }
    vector<int> upper(G, INF);
    upper[src]=0;
    for(int iter=0; iter<G-1; ++iter){
        for(int here=0; here<G; ++here) {
            for (auto t:adj[here]) {
                int there=t.first;
                int cost=t.second;
                if(upper[there]>upper[here]+cost){
                    upper[there]=upper[here]+cost;
                }
            }
        }
    }
    // 음수 사이클
    for(int here=0; here<G; ++here){
        for(auto t:adj[here]){
            int there=t.first;
            int cost=t.second;
            if(upper[there]>upper[here]+cost){
                if(reachable[src][here] && reachable[here][target])
                    return -INF;
            }
        }
    }
    return upper[target];
}

int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>G>>W;
        adj.clear();
        adj.resize(G);
        memset(reachable, false, sizeof(reachable));

        for(int i=0; i<G; ++i){
            reachable[i][i]=true;
        }

        for(int i=0; i<W; ++i){
            int a, b, d;
            cin>>a>>b>>d;
            adj[a].push_back({b, d});
            reachable[a][b]=true;
        }

        int past=bellmanFord(0, 1);
        if(!reachable[0][1]){
            cout<<"UNREACHABLE"<<'\n';
            continue;
        }

        if(past==INF || past==-INF)
            cout<<"INFINITY"<<" ";
        else
            cout<<past<<" ";

        for(int i=0; i<G; ++i){
            for(int j=0; j<adj[i].size(); ++j){
                adj[i][j].second=-adj[i][j].second;
            }
        }

        int future=bellmanFord(0, 1);
        if(future==INF || future==-INF)
            cout<<"INFINITY"<<'\n';
        else
            cout<<-future<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}