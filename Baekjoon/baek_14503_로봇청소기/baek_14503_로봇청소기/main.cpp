//
//  main.cpp
//  baek_14503_로봇청소기
//
//  Created by 윤정인 on 2018. 9. 24..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

using namespace std;

int dx[4]={0, -1, 0, 1}, dy[4]={-1,0,1,0};
int initd[4] = {0, 3, 2, 1};
int N, M;
int board[50][50];
int answer=0;

void dfs(int y, int x, int d){
    // 종료조건
    if(board[y][x]!=2){
        board[y][x]=2;
        answer++;
    }
    bool chk=true;
    for(int i=0; i<4; ++i){
        int rd = (i+d+1)%4;
        int rx = x+dx[rd], ry=y+dy[rd];
        if(!board[ry][rx]) {
            dfs(ry,rx, rd);
            chk = false;
            break;
        }
    }
    
    if(chk){
        int rx = x + dx[(d+2)%4], ry = y + dy[(d+2)%4];
        if(board[ry][rx]==1)
            return;
        else
            dfs(ry, rx, d);
    }
    
    return;
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N >> M;
    int r,c, d;
    cin >> r >> c >> d;
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j)
            cin >> board[i][j];
    }
    
    dfs(r,c,initd[d]);
    cout << answer;
    //std::cout << "Hello, World!\n";
    return 0;
}
