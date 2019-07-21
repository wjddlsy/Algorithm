//
//  main.cpp
//  baek_15685_드래곤커브
//
//  Created by 윤정인 on 2018. 9. 24..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool board[101][101];

int dx[4]={1, 0, -1, 0}, dy[4]={0,-1,0,1};

vector<int> dir;
void dragon(int x, int y, int d, int g ){
    board[y][x]=true;
    for(int i=0; i<g; ++i){
        int n = dir.size();
        for(int i=n-1; i>=0; --i){
            dir.push_back((dir[i]+1)%4);
        }
    }
    
    for(int i=0; i<dir.size(); ++i){
        x += dx[dir[i]];
        y += dy[dir[i]];
        board[y][x] = true;
        
    }
   
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, x, y, d, g;
    
    cin >> N;
    
    vector<pair<int, int>> point;
    while(N--){
         cin >> x >> y >> d >> g;
        dir.clear();
        dir.push_back(d);
        dragon(x, y, d, g);
    }
    
    int answer=0;
    
    for(int i=0; i<=99; ++i){
        for(int j=0; j<=99; ++j){
                if(board[i][j] & board[i+1][j] & board[i+1][j+1] & board[i][j+1])
                    answer++;
            
        }
    }
    
    cout << answer;
    //std::cout << "Hello, World!\n";
    return 0;
}
