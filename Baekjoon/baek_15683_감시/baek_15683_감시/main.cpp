//
//  main.cpp
//  baek_15683_감시
//
//  Created by 윤정인 on 2018. 9. 22..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define MAX_NM 8

int dx[4]={0,1,0,-1}; int dy[4]={1,0,-1,0};

int board[MAX_NM][MAX_NM];
bool check[MAX_NM][MAX_NM];
vector<pair<int, pair<int, int>>> cctv;
vector<vector<unsigned long long>> prob;


int N, M;

unsigned long long cell(unsigned long long y, unsigned long long int x){
    int a=y*M +x;
    return 1ULL << (y*M+ x);
}
bool isRange(int y, int x){
    if(x>=M || x<0 || y>=N || y<0)
        return false;
    return true;
    
}

void ch(int what, int i, int y, int x){
    unsigned long long up=0, down=0, left=0, right=0;
    int tx=x, ty=y;
    //up
    while(isRange(y, x) && board[y][x]!=6){
        
        if(board[y][x]==0)
            up |= cell(y, x);
        y++;
    }
    //down
    x=tx; y=ty;
    while(isRange(y, x) && board[y][x]!=6){
        if(board[y][x]==0)
            down |= cell(y,x);
        y--;
    }
    //left
    x=tx; y=ty;
    while(isRange(y, x) && board[y][x]!=6){
        if(board[y][x]==0)
            left |= cell(y,x);
        x--;
    }
    //right
    x=tx; y=ty;
    while(isRange(y, x) && board[y][x]!=6){
        if(board[y][x]==0)
            right |= cell(y,x);
        x++;
    }
    
    if (what==1){
        prob[i].push_back(up);
        prob[i].push_back(down);
        prob[i].push_back(left);
        prob[i].push_back(right);
    }
    
    else if (what==2){
        prob[i].push_back(up|down);
        prob[i].push_back(right|left);
    }
    
    else if(what==3){
        prob[i].push_back(up|left);
        prob[i].push_back(up|right);
        prob[i].push_back(down|left);
        prob[i].push_back(down|right);
    }
    
    else if(what==4){
        prob[i].push_back(up|left|down);
        prob[i].push_back(up|left|right);
        prob[i].push_back(up|right|down);
        prob[i].push_back(right|left|down);
    }
    
    else if(what==5){
        prob[i].push_back(up|left|down|right);
    }
}

int Number_of_Integer(unsigned long long input_value)
{
    
    unsigned int number_of_bits_set = 0;
    
    for (; input_value > 0 ; input_value >>= 1)
        
        number_of_bits_set += input_value & 1;
    
    return number_of_bits_set;
}

int max_n=0;
//unsigned long long sum=0;
vector<unsigned long long> test;
void ch2(int pos, unsigned long long sum){
    
    if(pos==prob.size()) {
        sum = 0;
        for(int i=0; i<test.size(); ++i){
            sum |= test[i];
        }
        int n = Number_of_Integer(sum);
        max_n=max(n, max_n);
        return;
    }
    
    for(int i=0; i<prob[pos].size(); ++i){

        
        sum|=prob[pos][i];
        test.push_back(prob[pos][i]);
        ch2(pos+1, sum);
        test.pop_back();
        //sum=0;
        //sum|=ch2(pos+1);
    }
    
    
    //return max(max_n, Number_of_Integer(sum));
    
}

void calculate(){
    prob = vector<vector<unsigned long long>>(cctv.size());
    for(int i=0; i<cctv.size(); ++i){
        ch(cctv[i].first, i, cctv[i].second.first, cctv[i].second.second);
    }
    
    ch2(0, 0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N >> M;
    int cnt=0;
    for(int i=0; i<N; ++i){
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
            if(board[i][j]!=0 && board[i][j]!=6)
                cctv.push_back(make_pair(board[i][j],make_pair(i, j)));
            else if(board[i][j]==0)
                cnt++;
        }
    }
    calculate();
    cout << cnt-max_n;
    return 0;
}
