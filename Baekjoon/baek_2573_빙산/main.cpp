#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int board[300][300];
bool visited[300][300];
int N, M;
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

bool isRange(int x, int y) {
    return x>=0 && x<N && y>=0 && y<M;
}

void remove() {
    int ice[300][300]={0,};

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(board[i][j]<=0)
                continue;
            int cnt=0;
            for(int k=0; k<4; ++k) {
                if(!isRange(i+dx[k], j+dy[k]))
                    continue;
                if(board[i+dx[k]][j+dy[k]]<=0)
                    cnt++;
            }
            ice[i][j]=cnt;
        }
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            board[i][j]-=ice[i][j];
        }
    }
}

void dfs(int x, int y) {
    if(visited[x][y])
        return;
    visited[x][y]=true;
    for(int i=0; i<4; ++i) {
        int nx=x+dx[i], ny=y+dy[i];
        if(!isRange(nx, ny))
            continue;
        if(board[nx][ny]<=0)
            continue;
        dfs(nx, ny);
    }
}

int dfsAll() {
    int cnt=0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(visited[i][j])
                continue;
            if(board[i][j]>0) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    int t=0;
    while (true) {
        if(dfsAll()==0) {
            cout<<0;
            break;
        }
        if(dfsAll()>1) {
            cout<<t;
            break;
        }
        t++;
        remove();
    }
    return 0;
}