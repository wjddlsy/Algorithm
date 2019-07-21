//
//  main.cpp
//  baek_15686_치킨배달
//
//  Created by 윤정인 on 2018. 9. 24..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int N, M, sum = 0, ret=987654321;
int board[50][50];
vector<pair<int,int>> chicken;
vector<pair<int, int>> home;

void cal(vector<int> picked){
    sum = 0;
    for(int i=0; i<home.size(); ++i){
        int min = 987654321;
        for(int j=0; j<picked.size(); ++j){
            min=std::min(min, dist(home[i].first, home[i].second, chicken[picked[j]].first, chicken[picked[j]].second));
        }
        sum += min;
    }
    
    ret=std::min(ret, sum);

}
void pick(int n, vector<int> &picked, int toPick){
    if(toPick==0) {
        cal(picked);
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
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
            if(board[i][j]==2)
                chicken.push_back({i,j});
            else if(board[i][j]==1)
                home.push_back({i,j});
        }
    }
    
    int cn = chicken.size();
    vector<int> picked;
    pick(cn, picked,M);
    
    cout << ret;
    
   // std::cout << "Hello, World!\n";
    return 0;
}
