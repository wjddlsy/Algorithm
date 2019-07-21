#include <iostream>

using namespace std;

int N, M, board[4][4], visited[4][4], dr[] = {0, 1}, dc[] = {1, 0};

// 그럼 이건 뭘까.. r, c에서 최댓값?
int solve(int r, int c) {
    if (r == N) return 0;
    if (c == M) return solve(r + 1, 0);
    if (visited[r][c]) return solve(r, c + 1);
    visited[r][c] = true;
    int ret = 0, num;
    for (int i = 0; i < 2; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        num = board[r][c];
        if (nr < N && nc < M) {
            while (nr < N && nc < M && !visited[nr][nc]) {
                visited[nr][nc]=true;
                num=num*10+board[nr][nc];
                ret=max(ret, solve(r, c+1)+num);
                nr+=dr[i], nc+=dc[i];
            }
            nr-=dr[i], nc-=dc[i];
            while(!(nr==r && nc==c)) {
               visited[nr][nc]=false;
               nr-=dr[i], nc-=dc[i];
            }
        }
    }
    ret=max(ret, board[r][c]+solve(r, c+1));
    visited[r][c]=false;
    return ret;
}

int main() {
    return 0;
}