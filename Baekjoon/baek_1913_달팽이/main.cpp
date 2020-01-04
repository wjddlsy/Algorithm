#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, pos;
    cin >> N >> pos;

    vector<vector<int>> board(N, vector<int>(N));

    board[(N + 1) / 2 - 1][(N + 1) / 2 - 1] = 1;
    int num = 2;
    pair<int, int> ans;
    for (int i = 1; i <= N; i += 2) {
        // start point : N-i, N
        // end point : N-i, N-i
        int x = (N + 1) / 2 - (i + 1) / 2, y = (N + 1) / 2 - (i + 1) / 2;
        int cnt = 0;
        for (int j = (i - 2) * (i - 2) + 1; j <= i * i; ++j) {
            if (i == 1) {
                break;
            }
            if (cnt / (i - 1) == 0) {
                y++;
            } else if (cnt / (i - 1) == 1) {
                x++;
            } else if (cnt / (i - 1) == 2) {
                y--;
            } else {
                x--;
            }
            board[x][y] = num;
            if (num == pos) {
                ans = {x + 1, y + 1};
            }
            num++;
            cnt++;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    cout << ans.first << " " << ans.second;
    // 가운데 좌표 : ()
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}