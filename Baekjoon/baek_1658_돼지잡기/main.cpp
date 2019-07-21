#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Edge{
    int target, capacity, flow;
    Edge* reverse;

    Edge(int target, int capacity): target(target), capacity(capacity){
        flow=0;
        reverse=nullptr;
    }

    int residualCapacity() const {
        return capacity-flow;
    }

    void push(int amt){
        flow+=amt;
        reverse->flow-=amt;
    }

};

int N, M;
vector<vector<Edge*>> adj;

void addEdge(int u, int v, int capacity){
    Edge* uv=new Edge(v, capacity), *vu=new Edge(u, 0);
    uv->reverse=vu;
    vu->reverse=uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int networkFlow(int src, int sink){

}
int main(){
    cin>>M>>N;
    vector<int> cages(M);
    vector<vector<int>> pigs;

    for(int i=0; i<M; ++i){
        cin>>M;
    }

    for(int i=0; i<N; ++i){
        int a, b;
        for(int j=0; j<a; ++j){
            int w;
            cin>>w;
            pigs[w].push_back(i);
        }
    }
}