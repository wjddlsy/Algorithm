//
//  main.cpp
//  baek_14500_테트로미노
//
//  Created by 윤정인 on 2018. 9. 23..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define MAX_NM 500

int N, M;
int board[MAX_NM][MAX_NM];
int MAX=0;

bool isRange(int y, int x){
    if(y>=N || y<0 || x>=M || x<0)
        return false;
    return true;
}

void straight(){
    for (int i=0; i<=N-4; ++i){
        for (int j=0; j<=M-4; ++j){
            for (int dx=0; dx<4; ++dx){
                MAX=std::max(MAX,board[i][j+dx] + board[i+1][j+dx] + board[i+2][j+dx] + board[i+3][j+dx]);
            }
            for (int dy=0; dy<4; ++dy){
                MAX=std::max(MAX, board[i+dy][j] + board[i+dy][j+1] + board[i+dy][j+2] + board[i+dy][j+3]);
            }
            
        }
    }
}

void square(){
    for(int i=0; i<=N-2; ++i){
        for (int j=0; j<=M-2; ++j){
            MAX=std::max(MAX, board[i][j]+board[i+1][j]+board[i][j+1] + board[i+1][j+1]);
        }
    }
}

void six(){
    int sum=0;
    for(int i=0; i<=N-3; ++i){
        for(int j=0; j<=M-2; ++j){
            sum =0;
            for (int dx=0; dx<2; ++dx){
                for (int dy=0; dy<3; ++dy)
                    sum += board[i+dy][j+dx];
            }
            // 1. L자 -> 4가지
            MAX=std::max(MAX, sum - board[i][j]-board[i+1][j]);
            MAX=std::max(MAX, sum - board[i][j+1]-board[i+1][j+1]);
            MAX=std::max(MAX, sum - board[i+1][j]-board[i+2][j]);
            MAX=std::max(MAX, sum - board[i+1][j+1]-board[i+2][j+1]);
            
            // 2. 티자 -> 2가지
            MAX=std::max(MAX, sum - board[i][j+1]- board[i+2][j+1]);
            MAX=std::max(MAX, sum - board[i][j] - board[i+2][j]);
            
            // 3. s자 -> 2가지
            MAX=std::max(MAX, sum -board[i][j+1]-board[i+2][j]);
            MAX=std::max(MAX, sum - board[i][j]-board[i+2][j+1]);
            
        }
    }
    
    for(int i=0; i<=N-2; ++i){
        for(int j=0; j<=M-3; ++j){
            sum =0;
            for (int dx=0; dx<3; ++dx){
                for (int dy=0; dy<2; ++dy)
                    sum += board[i+dy][j+dx];
            }
            // 1. L자 -> 4가지
            MAX=std::max(MAX, sum - board[i][j]-board[i][j+1]);
            MAX=std::max(MAX, sum - board[i][j+1]-board[i][j+2]);
            MAX=std::max(MAX, sum - board[i+1][j]-board[i+1][j+1]);
            MAX=std::max(MAX, sum - board[i+1][j+1]-board[i+1][j+2]);
            
            // 2. 티자 -> 2가지
            MAX=std::max(MAX, sum - board[i][j]- board[i][j+2]);
            MAX=std::max(MAX, sum - board[i+1][j] - board[i+1][j+2]);
            
            // 3. s자 -> 2가지
            MAX=std::max(MAX, sum - board[i+1][j]-board[i][j+2]);
            MAX=std::max(MAX, sum - board[i][j]-board[i+1][j+2]);
            
        }
    }
}
vector<int> result;
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for (int j=0; j<M; ++j)
            cin >> board[i][j];
    }
    straight();
    square();
    six();
    
    cout << MAX;
    
    return 0;
}
