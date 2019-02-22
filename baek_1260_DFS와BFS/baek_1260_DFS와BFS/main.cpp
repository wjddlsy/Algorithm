//
//  main.cpp
//  baek_1260_DFS와BFS
//
//  Created by 윤정인 on 2018. 8. 10..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, V;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> route_dfs;
void dfs(int start){
    if(visited[start])
        return ;
    visited[start]=true;
    route_dfs.push_back(start);
    
    for (int i=0; i<adj[start].size(); ++i){
        int there=adj[start][i];
        dfs(there);
    }
}

vector<int> bfs(int start){
    // 각 정점의 방문 여부
    vector<int> discovered(adj.size(), false);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    
    // 정점 방문 순서
    vector<int> order;
    
    discovered[start]=true;
    q.push(start);
    
    while(!q.empty()){
        int here = q.front();
        q.pop();
        
        order.push_back(here);
        
        for(int i=0; i<adj[here].size(); ++i){
            int there=adj[here][i];
            
            if(!discovered[there]){
                q.push(there);
                discovered[there]=true;
            }
            
        }
    }
    return order;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a, b;
    cin >> N >> M >> V;
    adj=vector<vector<int>>(N);
    visited=vector<bool>(N, false);
    
    for (int i=0; i<M; ++i){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for (int i=0; i<N; ++i){
        sort(adj[i].begin(), adj[i].end());
        
    }
    
    dfs(V-1);
    
    for(auto x : route_dfs){
        cout << x+1 << " ";
    }
    
    cout << endl;
    for(auto x: bfs(V-1)){
        cout << x+1 << " ";
    }
    return 0;
}
