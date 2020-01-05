#include <iostream>
#include <vector>

using namespace std;

int board[100][100], N, maxHeight = 0;
bool visited[100][100];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

bool isRange(int x, int y) {
    if (x >=0  && x < N && y >= 0 && y < N)
        return true;
    return false;
}

void dfs(int x, int y, int rain) {
    if(visited[x][y])
        return;
    visited[x][y] = true;
    for(int i=0; i<4; ++i) {
        int nx = x+dx[i], ny = y+dy[i];
        if(!isRange(nx, ny))
            continue;
        if(board[nx][ny] <= rain)
            continue;
        dfs(nx, ny, rain);
    }
}

int dfsAll(int rain) {
    int ret = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            visited[i][j] = false;
        }
    }

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(visited[i][j])
                continue;
            if(board[i][j] <= rain)
                continue;
            else {
                dfs(i, j, rain);
                ret++;
            }
        }
    }
    return ret;
}

int rain() {
    int ret = 1;
    for(int i=1; i<maxHeight; ++i) {
        ret = max(ret, dfsAll(i));
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> board[i][j];
            maxHeight = max(maxHeight, board[i][j]);
        }
    }
    cout << rain();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
