#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int adj[500][500], W[500][500];
int v[500];
int V, E;
int floyd(){
    vector<pair<int, int>> order;
    for(int i=0; i<V; ++i){
        order.push_back({v[i], i});
    }
    sort(order.begin(), order.end());
    for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
            if(i==j)
                W[i][j]=0;
            else
                W[i][j]=adj[i][j];
        }
    }
    int ret=987654321;
    for(int k=0; k<V; ++k){
        int w=order[k].second;
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j){
                adj[i][j]=min(adj[i][j], adj[i][w]+adj[w][j]);
                W[i][j]=min(adj[i][w]+v[w]+adj[w][j], W[i][j]);
            }
        }
    }
}
int main() {
    cin>>V>>E;
    for(int i=0; i<V; ++i){
        cin>>v[i];
    }

    for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
            adj[i][j]=987654321;
        }
    }

    for(int i=0; i<E; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a][b]=c;
        adj[b][a]=c;
    }


    floyd();

    int T;
    cin>>T;
    while(T--){
        int a, b;
        cin>>a>>b;
        a--; b--;
        cout<<W[a][b]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}