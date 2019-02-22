//
//  main.cpp
//  baek_6086_최대유량
//
//  Created by 윤정인 on 2018. 8. 7..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int INF=987654321;
int V;

int flow[52][52];
int capacity[52][52];
vector<int> adj[52];
int networkFlow(int source, int sink){
    memset(flow, 0, sizeof(flow));
    int totalFlow=0;
    while(true){
        //bfs
        vector<int> parent(52, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        
        while(!q.empty() && parent[sink]==-1){
            int here=q.front(); q.pop();
            for (auto there : adj[here]){
                if(capacity[here][there]-flow[here][there]>0 && parent[there]==-1){
                    q.push(there);
                    parent[there]=here;
                }
            }
        }
        // 증가 경로가 없으면 종료
        if(parent[sink]==-1) break;
        // 증가 경로를 통해 유량을 얼마나 보낼 지 결정
        int amount=INF;
        for (int p=sink; p!=source; p=parent[p])
            amount=min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        
        for(int p=sink; p!=source; p=parent[p]){
            flow[parent[p]][p]+=amount;
            flow[p][parent[p]]-=amount;
        }
        
        totalFlow+=amount;
        
    }
    return totalFlow;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N, c;
    char a, b;
    cin >> N;
    
    for (int i=0; i<N; ++i){
        cin >> a >> b >> c;
        capacity[a-'A'][b-'A']+=c;
        capacity[b-'A'][a-'A']+=c;
        adj[a-'A'].push_back(b-'A');
        adj[b-'A'].push_back(a-'A');
    }
    
    cout << networkFlow('A'-'A', 'Z'-'A');
    
    //std::cout << "Hello, World!\n";
    return 0;
}
