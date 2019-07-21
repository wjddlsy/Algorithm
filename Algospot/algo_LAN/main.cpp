#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int N, M;

const double INF=std::numeric_limits<double>::max();
vector<pair<int, int>> pos;
vector<vector<pair<int, double>>> adj;

double getDist(pair<int, int> a, pair<int, int> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

double prim(vector<bool> &added){
    vector<double> minWeight(N, INF), parent(N, -1);
    double ret=0;
    minWeight[0]=parent[0]=0;
    for(int iter=0; iter<N; ++iter){
        int u=-1;
        for(int v=0; v<N; ++v){
            if(!added[v] && (u==-1 || minWeight[u]>minWeight[v]))
                u=v;
        }
        if(u==-1)
            continue;
        ret+=minWeight[u];
        added[u]=true;
        for(int i=0; i<adj[u].size(); ++i){
            int v=adj[u][i].first;
            double weight=adj[u][i].second;
            if(!added[v] && minWeight[v]>weight){
                parent[v]=u;
                minWeight[v]=weight;
            }
        }
    }
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>N>>M;
        pos=vector<pair<int, int>>(N);
        adj=vector<vector<pair<int, double>>>(N);
        for(int i=0; i<N; ++i){
            cin>>pos[i].first;
        }
        for(int i=0; i<N; ++i) {
            cin >> pos[i].second;
        }

        for(int i=0; i<N; ++i){
            for(int j=i+1; j<N; ++j){
                double dist=getDist(pos[i], pos[j]);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<bool> added(N, false);
        for(int i=0; i<M; ++i){
            int a, b;
            cin>>a>>b;
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }

        double ret=prim(added);
        printf("%.10f \n", ret);
        //cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}