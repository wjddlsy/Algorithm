//
//  main.cpp
//  baek_14890_경사로
//
//  Created by 윤정인 on 2018. 9. 26..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int N, L, answer=0;



void check(int board[][101],int pos){
    vector<int> list;
    int same=1;
    board[pos][N]=board[pos][N-1]-1;
    bool bridege[100]={0,};
    // 높은 칸을 만난 경우
    for (int i=0; i<N; ++i){
        if(board[pos][i+1]==board[pos][i]+1){
            if(list.empty()){
                if(same<L)
                    return;
            }
            
            else {
                if(same<2*L)
                    return;
                list.pop_back();
            }
            
            same=1;
        }
        
        else if(board[pos][i+1]==board[pos][i]-1){
            if(!list.empty()){
                if(same<L)
                    return;
                list.pop_back();
            }
        
            list.push_back(i+1);
            
            same=1;
        }
        else if(board[pos][i]==board[pos][i+1]){
            same++;
        }
        else
            return;
        
    }
    
    answer++;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N >> L;
    
    int board1[101][101]={0,};
    int board2[101][101]={0,};
    
    int in;
    for(int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            cin >> in;
            board1[i][j]=in;
            board2[j][i]=in;
        }
    }
    
    for(int i=0; i<N; ++i){
        check(board1, i);
        check(board2, i);
    }
    
    cout << answer;
    return 0;
}
