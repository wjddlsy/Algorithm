#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int adj[10][10];
const int INF=987654321;
int main() {
    int N;
    cin>>N;
    int ret=987654321;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>adj[i][j];
        }
    }
    vector<int> route(N);
    for(int i=0; i<N; ++i){
        route[i]=i;
    }

    do {
        int cost=adj[route[N-1]][route[0]];
        if(cost==0)
            continue;
        for(int i=0; i<N-1; ++i){
            if(adj[route[i]][route[i+1]]==0) {
                cost=INF;
                break;
            }
            cost+=adj[route[i]][route[i+1]];
        }
        ret=min(ret, cost);
    } while(next_permutation(route.begin(), route.end()));
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}