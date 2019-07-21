#include <vector>
#include <iostream>

using namespace std;

#define INF 987654321
int adj[300][300];
int V;

void floyd(){
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin>>C;
    while(C--){
        int N, M;
        cin>>V>>M>>N;
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j) {
                if (i == j)
                    adj[i][j] = 0;
                else
                    adj[i][j] = INF;
            }
        }
        for(int i=0; i<M; ++i){
            int a, b, c;
            cin>>a>>b>>c;
            adj[a][b]=min(adj[a][b],c);
            adj[b][a]=min(adj[b][a],c);
        }

        floyd();
        int ret=0;
        for(int t=0; t<N; ++t){
            int a, b, c;
            cin>>a>>b>>c;
            if(adj[a][b]<=c){
                ret++;
                continue;
            }
            vector<int> K;
            K.push_back(a);
            K.push_back(b);

            adj[a][b]=adj[b][a]=c;
            for(auto k:K){
                for(int i=0; i<V; ++i){
                    for(int j=0; j<V; ++j){
                        if(adj[i][j]>adj[i][k]+adj[k][j]){
                            adj[i][j]=adj[i][k]+adj[k][j];
                        }
                    }
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}

