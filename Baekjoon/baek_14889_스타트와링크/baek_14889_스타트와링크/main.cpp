//
//  main.cpp
//  baek_14889_스타트와링크
//
//  Created by 윤정인 on 2018. 9. 26..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int board[20][20];
int N, ret=987654321;

int dist(vector<int> first, vector<int> second){
    int sum1=0, sum2=0;
    for(int i=0; i<first.size(); ++i){
        for(int j=i+1; j<first.size(); ++j){
            sum1+=(board[first[i]][first[j]]+board[first[j]][first[i]]);
        }
    }
    
    for(int i=0; i<second.size(); ++i){
        for(int j=i+1; j<second.size(); ++j){
            sum2+=(board[second[i]][second[j]]+board[second[j]][second[i]]);
        }
    }
    
    return abs(sum1-sum2);
}

void pick(int n, vector<int> &picked, int toPick){
    if(toPick==0) {
        vector<int> first = picked;
        first.push_back(N-1); // 마지막애 넣어주기
        vector<int> picked2;
        for(int i=0; i<N; ++i){
            picked2.push_back(i);
            for(int j=0; j<first.size(); ++j){
                if(first[j]==i){
                    picked2.pop_back();
                    break;
                }
            }
        }
        
        ret=min(ret,dist(first, picked2));
        return;
    }
    
    int smallest = picked.empty() ? 0: picked.back()+1;
    
    for(int next = smallest; next<n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> board[i][j];
        }
    }
    
    vector<int> picked;
    pick(N-1, picked, N/2-1);
    cout << ret;
    //std::cout << "Hello, World!\n";
    return 0;
}
