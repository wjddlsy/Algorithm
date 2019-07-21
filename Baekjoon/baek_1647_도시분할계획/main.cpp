#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> adj;
vector<tuple<int, int, int>> edges;

struct UnionFind{
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
        u=find(u); v=find(v);
        if(u==v)
            return;
        if(rank[u]>rank[v])
            swap(u, v);
        parent[u]=v;
        if(rank[u]==rank[v])
            rank[v]++;

    }
};

int kruskal(){
    sort(edges.begin(), edges.end());
    UnionFind sets(N);
    int ret=0;
    int maxCost=0;
    for(auto edge:edges){
        int cost, u, v;
        tie(cost, u, v)=edge;
        if(sets.find(u)==sets.find(v))
            continue;
        sets.merge(u, v);
        maxCost=max(maxCost, cost);
        ret+=cost;
    }
    return ret-maxCost;
}
int main() {
    cin>>N>>M;
    adj.resize(N);
    for(int i=0; i<M; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edges.push_back({c, a, b});
        //edges.push_back({c, b, a});
    }
    cout<<kruskal();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}