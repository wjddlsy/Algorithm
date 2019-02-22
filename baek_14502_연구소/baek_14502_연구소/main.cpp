//
//  main.cpp
//  baek_14502_연구소
//
//  Created by 윤정인 on 2018. 7. 31..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 8;

int N, M, numZ=0, cnt=0, ret=0;
int arr[MAX][MAX];
int arrN[MAX][MAX];
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
bool visited[MAX][MAX];
vector<pair<int, int>> zero;
vector<pair<int, int>> two;
vector<int> wall;



bool isRange(int x, int y){
    if(x<0 || x>=N || y<0 || y>=M)
        return false;
    return true;
}

void dfs(int x, int y){
    // 기저사례
    if(!isRange(x, y))
        return;
    if(visited[x][y])
        return;
    
    visited[x][y]=true;
    
    
    for (int i=0; i<4; ++i){
        int ax = x+ dx[i];
        int ay = y+ dy[i];
        if(arrN[ax][ay]==0) {
            //arrN[ax][ay]=2;
            dfs(ax, ay);
        }
    }
    
}

void init(){
    for(int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            arrN[i][j]=arr[i][j];
        }
    }
    
    
    
    for (int i=0; i<3; ++i){
        int x=zero[wall[i]].first, y=zero[wall[i]].second;
        arrN[x][y]=1;
    }
    
    for(int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            visited[i][j]=false;
        }
    }
    
    cout << endl;
    for(int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            cout << arrN[i][j] << " ";
        }
        cout << endl;
    }
    
    
    cnt=0;
    
    for (int i=0; i<two.size(); ++i){
        int x=two[i].first, y=two[i].second;
        dfs(x, y);
        
    }
    
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arrN[i][j]==0 && !visited[i][j]) cnt++;
        }
    }
    ret = max(ret, cnt);
}

void make_wall(){
    vector<int> n;
    
    vector<bool> v(numZ);
    fill(v.begin(), v.begin()+3, true);
    
    do{
        for(int i=0; i<numZ; ++i){
            if(v[i])
                wall.push_back(i);
        }
        init();
        wall.clear();
    } while(prev_permutation(v.begin(), v.end()));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int input;
    
    /* input */
    cin >> N >> M;
    for (int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            cin >> input;
            if (input == 0 ){
                zero.push_back(make_pair(i, j));
                numZ++;
            }
            else if (input == 2){
                two.push_back(make_pair(i, j));
            }
            arr[i][j]=input;
        }
    }
    
    make_wall();
    
    std::cout << ret;
    
    return 0;
}
