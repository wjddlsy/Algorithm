#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool board[100][100];
bool visited[100][100];
int dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1};
int M, N, cnt=0;
vector<int> ret;

bool isRange(int x, int y) {
    return x>=0 && x<M && y>=0 && y<N;
}

void dfs(int x, int y, int& sum) {
    if(!isRange(x, y))
        return;
    if(visited[x][y])
        return;
    if(board[x][y])
        return;
    visited[x][y]=true;
    sum++;
    for(int i=0; i<4; ++i) {
        dfs(x+dx[i], y+dy[i], sum);
    }
}

void dfsAll() {
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            if(visited[i][j])
                continue;
            int sum=0;
            dfs(i, j, sum);
            if(sum>0)
                ret.emplace_back(sum);
        }
    }
}
int main() {
    int K;
    cin>>M>>N>>K;
    for(int i=0; i<K; ++i) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1; x<x2; ++x) {
            for(int y=y1; y<y2; ++y) {
                board[y][x]=true;
            }
        }
    }
    dfsAll();
    sort(ret.begin(), ret.end());
    cout<<ret.size()<<'\n';
    for(auto &r:ret) {
        cout<<r<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}