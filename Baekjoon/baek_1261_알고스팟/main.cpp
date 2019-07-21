#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

int M, N;
const int INF=987654321;
int board[100][100];
int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
bool isRange(pair<int, int> pos){
    if(pos.first<0 || pos.first>=N || pos.second<0 || pos.second>=M)
        return false;
    return true;
}
int dijikstra(){
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> dist(N, vector<int>(M, INF));
    pq.push({0,{0, 0}});
    dist[0][0]=0;
    while(!pq.empty()){
        pair<int, int> here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[here.first][here.second]<cost)
            continue;
        for(int i=0; i<4; ++i){
            pair<int, int> there={here.first + dx[i], here.second+dy[i]};
            if(!isRange(there))
                continue;
            int nextDist=cost+board[there.first][there.second];
            if(nextDist<dist[there.first][there.second]){
                dist[there.first][there.second]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist[N-1][M-1];
}
int main() {
    cin>>M>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            scanf(" %1d", &board[i][j]);
        }
    }
    cout<<dijikstra();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}