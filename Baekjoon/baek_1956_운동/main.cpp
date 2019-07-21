#include <iostream>
#include <vector>

using namespace std;

const int INF=100000000;
int V, E;
int adj[400][400];
int main() {
    cin>>V>>E;
    for(int i=0; i<V; ++i){
        for(int j=0; j<V; ++j){
            adj[i][j]=INF;
        }
    }
    for(int i=0; i<E; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a][b]=c;
    }

    for(int k=0; k<V; ++k){
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    int minV=INF;
    for(int i=0; i<V; ++i){
        minV=min(minV, adj[i][i]);
    }

    cout<<(minV==INF?-1:minV);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}