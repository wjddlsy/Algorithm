#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
const int INF=987654321;
int adj[5000][5000];

void floyd(){
    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
}
int main() {
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            adj[i][j]=INF;
        }
        adj[i][i]=0;
    }
    for(int i=0; i<M; ++i){
        int A, B;
        cin>>A>>B;
        A--; B--;
        adj[A][B]=1;
        adj[B][A]=1;
    }
    floyd();

    vector<pair<int, int>> values;
    for(int i=0; i<N; ++i){
        int sum=0;
        for(int j=0; j<N; ++j){
            sum+=adj[i][j];
        }
        values.push_back({sum, i});
    }

    sort(values.begin(), values.end());
    cout<<values[0].second+1;


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}