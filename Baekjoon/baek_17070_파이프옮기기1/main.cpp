#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
int board[16][16];
vector<tuple<int, int, int>> moves[3];

int cnt=0;

bool isRange(int x, int y){
    return x>=0&&x<N&&y>=0&&y<N;
}

void dfs(int here, int dir){
    if(here==N*N-1){
        cnt++;
        return;
    }
    int x=here/N, y=here%N;
    for(int i=0; i<moves[dir].size(); ++i){
        int dx, dy, nd;
        tie(dx, dy, nd)=moves[dir][i];
        int nx=x+dx, ny=y+dy;
        if(!isRange(nx, ny))
            continue;
        if(board[nx][ny]==1)
            continue;
        if(nd==2){
            if(board[nx-1][ny]==1 || board[nx][ny-1]==1)
                continue;
        }
        dfs(nx*N+ny, nd);
    }
    return;
}

int main() {
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>board[i][j];
        }
    }
    moves[0].push_back({0, 1, 0});
    moves[0].push_back({1, 1, 2});
    moves[1].push_back({1, 0, 1});
    moves[1].push_back({1,1, 2});
    moves[2].push_back({0, 1, 0});
    moves[2].push_back({1, 0, 1});
    moves[2].push_back({1,1, 2});
    dfs(1, 0);
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}