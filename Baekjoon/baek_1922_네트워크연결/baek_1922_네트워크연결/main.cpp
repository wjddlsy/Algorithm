//
//  main.cpp
//  최소신장트리
//
//  Created by 윤정인 on 2018. 7. 24..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) : parent(n) {
        for (int i=0; i<n; ++i)
            parent[i]=i;
    }
    
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return;
        parent[u]=v;
    }
    
};

const int MAX_V = 100000;
const int INF = 9876543321;
int V, E;

vector<pair<int, int>> adj[MAX_V];

int kruskal(vector<pair<int, int> > & selected){
    int ret=0;
    selected.clear();
    vector<pair<int, pair<int, int>>> edges;
    
    for (int u=0; u<V; ++u){
        for (int i=0; i< adj[u].size(); ++i){
            int v=adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u,v)));
        }
    }
    
    sort(edges.begin(), edges.end());
    DisjointSet sets(V);
    for(int i=0; i<edges.size(); ++i){
        int cost=edges[i].first;
        int u=edges[i].second.first, v=edges[i].second.second;
        if(sets.find(u)==sets.find(v)) continue;
        
        sets.merge(u,v);
        selected.push_back(make_pair(u,v));
        ret+=cost;
    }
    return ret;
}

void prim(){
    //selected.clear();
    vector<bool> added(V, false);
    vector<int> key(V, INF), parent(V, -1);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int src=0;
    
    pq.push(make_pair(0, src));
    
    key[src] = 0 ;
    
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        added[u]=true;
        
        vector< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;
            
            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (added[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    
    //    for (int i = 1; i < V; ++i)
    //        printf("%d - %d\n", parent[i], i);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int  a, b, c;
    cin >> V >> E;
    for(int i=0; i<E; ++i){
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(b-1, c));
    }
    
    vector<pair<int, int>> selected;
    
    std::cout << kruskal(selected)<< endl;
    prim();
    return 0;
}

