//
//  main.cpp
//  baek_2188_축사배정
//
//  Created by 윤정인 on 2018. 8. 9..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 200
#define MAX_M 200

int N, M,size=0;;
bool adj[MAX_N][MAX_M];

vector<bool> visited;
vector<int> aMatch, bMatch;


bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=0; b<M; ++b){
        if(adj[a][b]){
            if(bMatch[b]==-1 || dfs(bMatch[b])){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
                
            }
        }
    }
    return false;
}
int bipartiteMatch(){
    aMatch=vector<int>(N,-1);
    bMatch=vector<int>(M,-1);
    int size=0;
    for (int start=0; start<N; ++start){
        visited=vector<bool>(N,false);
        if(dfs(start))
            ++size;
    }
    return size;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int S, input;
    cin >> N >> M;
    for (int i=0; i<N; ++i){
        cin >> S;
        for (int j=0; j<S; ++j){
            cin >> input;
            adj[i][input-1]=true;
        }
            
    }
    std::cout << bipartiteMatch();
    return 0;
}
