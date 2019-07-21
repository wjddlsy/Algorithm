#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>


using namespace std;

vector<vector<int>> board(102, vector<int>(102, 5));
int dx[]={1,0,-1,0}, dy[]={0, 1,0,-1};
int dirs[6][4]={
        {0, 0, 0, 0},
        {2, 0, 3, 1},
        {2, 3, 1, 0},
        {1, 3, 0, 2},
        {3, 2, 0, 1},
        {2, 3, 0, 1}
};
vector<pair<pair<int,int>, pair<int, int>>> hole(11);
bool check_hole[11];
int N;

int main() {
    int t;
    cin >> t;
    for (int nt = 1; nt <= t; ++nt) {
        /*INPUT*/
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> board[i][j];
                if (board[i][j] > 5) {
                    if (!check_hole[board[i][j]]) {
                        hole[board[i][j]].first = {j, i};
                        check_hole[board[i][j]] = true;
                    } else
                        hole[board[i][j]].second = {j, i};
                }
            }
        }

        int ret = 0;
        for (int sx = 1; sx <= N; ++sx) {
            for (int sy = 1; sy <= N; ++sy) {
                int type = board[sy][sx];
                if (type == 0) {
                    for (int sdir = 0; sdir < 4; ++sdir) {
                        int score = 0;
                        int y = sy + dy[sdir], x = sx + dx[sdir];
                        int dir = sdir;
                        while (true) {
                            if (x == sx && y == sy)
                                break;
                            if (board[y][x] == -1)
                                break;
                            type = board[y][x];
                            if (type > 5) { //웜홀을 만난 경우
                                if (make_pair(x, y) == hole[type].first) {
                                    y = hole[type].second.second;
                                    x = hole[type].second.first;
                                } else {
                                    y = hole[type].first.second;
                                    x = hole[type].first.first;
                                }

                                y += dy[dir];
                                x += dx[dir];
                            } else if (type == 0) {
                                y = y + dy[dir];
                                x = x + dx[dir];

                            } else {
                                score++; // 벽이나 장애물 만난것
                                dir = dirs[type][dir];
                                y = y + dy[dir];
                                x = x + dx[dir];

                            }
                        }
                        ret = max(ret, score);
                    }
                }
            }
        }

        cout << "#" << nt << " " << ret << '\n';
        board = vector<vector<int>>(102, vector<int>(102, 5));
        memset(check_hole, 0, sizeof(check_hole));

    }
    return 0;
}