//
//  main.cpp
//  baek_2146_다리만들기
//
//  Created by 윤정인 on 2018. 8. 2..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool visited[100][100];
vector<vector<pair<int, int>>> island;
vector<pair<int, int>> temp;

int map[100][100];
int n, island_id;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isRange(int x, int y){
    if (x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}

bool isEdge(int x, int y){
    for (int i=0; i<4; ++i){
        int ax=x+dx[i], ay=y+dy[i];
        if(isRange(ax, ay)){
            if(!map[ax][ay])
                return true;
        }
    }

    return false;
    
}

void dfs(int x, int y){
    if(!isRange(x, y))
        return;
    if(visited[x][y])
        return;
    if(!map[x][y])
        return;
    
    visited[x][y]=true;
    
    if(isEdge(x, y))
        temp.push_back(make_pair(x, y));
    
    for (int i=0; i<4; ++i ){
        int ax=x+dx[i], ay=y+dy[i];
        dfs(ax, ay);
    }
    
}
int main(int argc, const char * argv[]) {
    // 입출력
    cin >> n;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j)
            cin >> map[i][j];
    }
    
    //dfs
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if(!visited[i][j] && map[i][j] ){
                dfs(i, j);
                island.push_back(temp);
                temp.clear();
            }
        }
    }
    
    int ans=1000, len;
    
    
    for (int i=0; i<island.size(); ++i){
        for (int j=i+1; j<island.size(); ++j){
            for (int k=0; k<island[i].size(); ++k){
                int x = island[i][k].first, y=island[i][k].second;
                
                for(int l=0; l<island[j].size(); ++l){
                    int x2 = island[j][l].first, y2=island[j][l].second;
                    len = abs(y2-y)+abs(x2-x) -1;
                    ans = min(ans, len);
                }
            }
            
        }
    }
    
    cout << ans;
    
    return 0;
}
