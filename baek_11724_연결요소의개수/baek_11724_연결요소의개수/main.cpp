//
//  main.cpp
//  baek_11724_연결요소의개수
//
//  Created by 윤정인 on 2018. 8. 10..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int N, M, ret=0;;

void dfs(int here){
    if(visited[here])
        return;
    
    visited[here]=true;
    for (int j=0; j<adj[here].size(); ++j){
        int there=adj[here][j];
        if(!visited[there])
            dfs(there);
    }
    
}
void dfsAll(){
    visited=vector<bool>(N,false);
    for (int i=0; i<N; ++i){
        if(!visited[i]){
            dfs(i);
            ret++;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N >> M;
    adj=vector<vector<int>>(N);
    int a, b;
    for (int i=0; i<M; ++i){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfsAll();
    cout << ret;
    return 0;
}
