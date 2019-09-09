#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, board[500][500], cache[500][500],
    dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

int solve(int r, int c) {
    if(r<0 || r>=N || c<0 || c>=M)
        return 0;
    if(r==N-1 && c==M-1)
        return 1;
    int &ret = cache[r][c];
    if(ret!=-1)
        return ret;
    ret = 0;
    for(int i=0; i<4; ++i) {
        int nr = r+dx[i], nc = c+dy[i];
        if(board[r][c] > board[nr][nc])
            ret += solve(nr, nc);
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}