#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std ;

int N;
vector<vector<pair<int, int>>> adj;
vector<tuple<int, int, int>> edges;
int getDist(tuple<int, int, int> a, tuple<int, int, int> b){
    int x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1)=a;
    tie(x2, y2, z2)=b;
    return min({abs(x1-x2), abs(y1-y2), abs(z1-z2)});
}

struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n):parent(n), rank(n, 1){
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
    }
    int find(int u){
        return u==parent[u]?u:parent[u]=find(parent[u]);
    }
    void merge(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return;
        if(rank[u]>rank[v])
            swap(u, v);
        parent[u]=v;
        if(rank[u]==rank[v])
            rank[v]++;
    }
};

int kruskal(){
    sort(edges.begin(), edges.end());
    int ret=0;
    UnionFind sets(N);
    for(auto edge:edges){
        int cost, u, v;
        tie(cost, u, v)=edge;
        if(sets.find(u)==sets.find(v))
            continue;
        ret+=cost;
        sets.merge(u, v);
    }
    return ret;
}

void push(int i, vector<pair<int, int>>& X){
    int dist=X[i+1].first-X[i].first;
    adj[X[i].second].push_back({X[i+1].second,  dist});
    edges.push_back({dist, X[i].second, X[i+1].second});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<tuple<int, int, int>> planets;
    vector<pair<int, int>> X, Y, Z;
    cin>>N;
    for(int i=0; i<N; ++i){
        int x, y, z;
        cin>>x>>y>>z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    adj.resize(N);
    for(int i=0; i<N-1; ++i){
        push(i, X);
        push(i, Y);
        push(i, Z);

    }
    cout<<kruskal();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}