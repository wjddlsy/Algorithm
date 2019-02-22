//
//  main.cpp
//  baek_1238_파티
//
//  Created by 윤정인 on 2018. 8. 10..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;


int N, M, X;




vector<int> dijkstra(vector<pair<int,int>> adj[],int src){
    
    vector<int> dist(N, INF);
    dist[src]=0;
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        
        for(int i=0; i<adj[here].size(); ++i){
            int there=adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            if(dist[there]>nextDist){
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int, int>> adj[1000];
    vector<pair<int, int>> adj2[1000];
    cin >> N >> M >> X;
    int a, b, c;
    for (int i=0; i<M; ++i){
        cin >> a >> b >> c;
        adj[b-1].push_back(make_pair(a-1, c));
        adj2[a-1].push_back(make_pair(b-1, c));
    }
    
    
    auto x=dijkstra(adj, X-1);
    auto y=dijkstra(adj2, X-1);
    int max = 0;
    for (int i=0; i<N; ++i){
        max = std::max(max, x[i]+y[i]);
    }
 
    cout << max ;
    return 0;
}
