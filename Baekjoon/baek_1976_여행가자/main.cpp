#include <iostream>
#include <vector>
using namespace std;

bool city[201][201];

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n):parent(n), rank(n, 1){
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
    }
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }

    void merge(int u, int v){
        u=find(u); v=find(v);
        if(u==v)
            return;
        if(rank[u]>rank[v]) swap(u, v);
        parent[u]=v;
        if(rank[u]==rank[v]) ++rank[v];

    }
};
int main() {
    int N, M, in;
    cin>>N>>M;
    DisjointSet ds(N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>in;
            if(in) {
                ds.merge(i, j);
            }
        }
    }
    vector<int> plan;
    for(int i=0; i<M; ++i){
        cin>>in;
        plan.push_back(in-1);
    }

    for(int i=0; i<M-1; ++i){
        if(ds.find(plan[i])!=ds.find(plan[i+1])){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}