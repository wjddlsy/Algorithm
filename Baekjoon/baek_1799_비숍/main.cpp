#include <iostream>

using namespace std;

int board[11][11], n, total = 0;
int diag1[22], diag2[22];
int ret[2];

void solve(int r, int c, int cnt, bool flag) {
    if (c >= n) {
        r++;
        c%2==0? c=1 : c=0;
    }
    if (r >= n) {
        ret[flag] = max(ret[flag], cnt);
        return;
    }
    if (board[r][c] && !diag1[c - r + n - 1] && !diag2[r + c]) {
        diag1[c - r + n - 1] = diag2[r + c] = 1;
        solve(r, c + 2, cnt + 1, flag);
        diag1[c - r + n - 1] = diag2[r + c] = 0;
    }
    solve(r, c+2, cnt, flag);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    solve(0, 0, 0, 0);
    solve(0, 1, 0, 1);
    cout << ret[0] + ret[1];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}