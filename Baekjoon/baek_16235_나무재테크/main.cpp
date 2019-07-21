#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
int board[10][10];
int curr[10][10];
int flow[10][10];
vector<vector<priority_queue<int>>> trees;

void plant(int i, int j){
    for(int x=-1; x<=1; ++x){
        for(int y=-1; y<=1; ++y){
            if(x==0 && y==0)
                continue;
            int ni=i+x, nj=j+y;
            if(ni<0 || ni>=N || nj<0 || nj>=N)
                continue;
            for(int cnt=0; cnt<flow[i][j]; ++cnt) {
                trees[ni][nj].push(-1);
            }

        }
    }
}
void fall_winter(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(flow[i][j]>0){
                plant(i, j);
            }
            curr[i][j]+=board[i][j];
        }
    }
    memset(flow, 0, sizeof(flow));
}

void spring_summer(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            bool flag=true;
            priority_queue<int> tree;
            while(!trees[i][j].empty()) {
                int young = -trees[i][j].top();
                trees[i][j].pop();
                if(!flag || young>curr[i][j]){
                    curr[i][j]+=(young/2);
                    flag=false;
                    continue;
                }
                curr[i][j]-=young;
                young++;
                tree.push(-young);
                if(young%5==0){
                    flow[i][j]++;
                }
            }
            trees[i][j]=tree;

        }
    }
}

void init(){
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            curr[i][j]=5;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M>>K;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>board[i][j];
        }
    }
    trees=vector<vector<priority_queue<int>>>(N, vector<priority_queue<int>>(N));
    for(int i=0; i<M; ++i){
        int x, y, z;
        cin>>x>>y>>z;
        x--; y--;
        trees[x][y].push(-z);
    }

    init();
    for(int i=0; i<K; ++i) {
        spring_summer();
        fall_winter();
        //winter();
    }

    int cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cnt+=trees[i][j].size();
        }
    }
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}