#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int m, n;
vector<vector<pair<int, int>>> adj;
vector<tuple<int, int, int>> edges;
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n):parent(n), rank(n, 1){
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
    }
    int find(int u){
        return u==parent[u]?u:(parent[u]=find(parent[u]));
    }
    void merge(int u, int v){
        u=parent[u], v=parent[v];
        if(u==v)
            return;
        if(rank[u]>rank[v])
            swap(u, v);
        parent[u]=v;
        if(rank[u]==rank[v]) ++rank[v];
    }
};

int kruskal(){
    UnionFind sets(m);
    int ret=0;
    for(int i=0; i<edges.size(); ++i){
        int u, v, cost;
        tie(cost, u, v)=edges[i];
        if(sets.find(u)==sets.find(v)) continue;
        sets.merge(u, v);
        ret+=cost;
    }
    return ret;
}
int main() {
    while(true){
        cin>>m>>n;
        if(n==0 && m==0)
            break;
        adj=vector<vector<pair<int, int>>>(n);
        edges.clear();
        int totalCost=0;
        for(int i=0; i<n; ++i){
            int x, y, z;
            cin>>x>>y>>z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
            edges.push_back({z, x, y});
            totalCost+=z;
        }
        sort(edges.begin(), edges.end());
        cout<<totalCost-kruskal()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}