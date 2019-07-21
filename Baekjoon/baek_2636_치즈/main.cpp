#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};
bool board[100][100];
bool visited[100][100];

int h, w, cnt=0;
bool isRange(int r, int c) {
    return r>=0 && r<h && c>=0 && c<w;
}

void dfs(int r, int c) {
    if(!isRange(r, c))
        return;
    if(visited[r][c])
        return;
    visited[r][c]=true;

    if(board[r][c]) {
        board[r][c]=0;
        cnt++;
        return;
    }

    for(int i=0; i<4; ++i) {
        int nr=r+dx[i], nc=c+dy[i];
        dfs(nr, nc);
    }
}

int dfsAll() {
    cnt=0;
    memset(visited, false, sizeof(visited));
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(!board[i][j]) {
                dfs(i, j);
                return cnt;
            }
        }
    }
    return cnt;
}

int main() {
    cin>>h>>w;
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            cin>>board[i][j];
        }
    }

    int t=0, cur=0, prev=0;
    cur=dfsAll();
    while(cur) {
        prev=cur;
        t++;
        cur=dfsAll();
    }
    cout<<t<<'\n'<<prev;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}