#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;



int n;
vector<vector<pair<int, double>>> adj;
vector<tuple<double, int, int>> edges;

double getDist(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

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

double kruskal(){
    sort(edges.begin(), edges.end());
    UnionFind sets(n);
    double ret;
    for(auto edge:edges){
        int u, v;
        double cost;
        tie(cost, u, v)=edge;
        if(sets.find(u)==sets.find(v))
            continue;
        sets.merge(u, v);
        ret+=cost;
    }
    return ret;
}

int main() {
    cin>>n;
    adj.resize(n);
    vector<pair<double, double>> stars;
    for(int i=0; i<n; ++i){
        double a, b;
        cin>>a>>b;
        stars.push_back({a, b});
    }
    for(int i=0; i<stars.size(); ++i){
        for(int j=0; j<stars.size(); ++j){
            double dist=getDist(stars[i], stars[j]);
            adj[i].push_back({j, dist});
            edges.push_back({dist, i, j});
        }
    }
    //sort(edges.begin(), edges.end());
    printf("%2f", kruskal());
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}