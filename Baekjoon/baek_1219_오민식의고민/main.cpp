#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const long long INF=1e18;
int N, M, S, E;
long long adj[100][100];
int money[100];

string floyd(){

    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    bool flag=true;
    for(int i=0; i<N; ++i){
        if(adj[i][i]<0 && adj[S][i]<INF/2 && adj[i][E]<INF/2){
            return "Gee";
        }
    }

    if(adj[S][E]>=INF/2)
        return "gg";
    if(flag){
        return to_string(-adj[S][E]+money[E]);
    }


}
int main() {
    cin>>N>>S>>E>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            adj[i][j]=INF;
        }
    }
    for(int i=0; i<M; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b], (long long)c);
    }

    for(int i=0; i<N; ++i){
        cin>>money[i];
        for(int j=0; j<N; ++j) {
            adj[i][j] -= money[i];
        }
        adj[i][i]=min(adj[i][i], 0LL);
    }

    cout<<floyd();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}