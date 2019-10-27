#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int LOGN = 11;
int board[1000][1000];
int st[1000][1000][LOGN][LOGN];
int cache[1000][1000];
int LOG[1001];
int n, m;

void precomputeLog() {
    LOG[1] = 0;
    for(int i=2; i<=1000; ++i) {
        LOG[i] = LOG[i/2] + 1;
    }
}

void precomputeCache() {
    for (int i = 0; i < n; ++i) {
        cache[i][0] = board[i][0];
    }
    for (int j = 0; j < m; ++j) {
        cache[0][j] = board[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (board[i][j] == 0) {
                cache[i][j] = 0;
            } else {
                cache[i][j] = min({cache[i - 1][j - 1], cache[i - 1][j], cache[i][j - 1]}) + 1;
            }
        }
    }
}

void precomputeST() {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            st[i][j][0][0] = cache[i][j];
        }
    }

    for (int i = 0; i < LOGN; ++i) {
        for (int j = 0; j < LOGN; ++j) {
            for (int r = 0; r + (1 << i) <= n; ++r) {
                for (int c = 0; c + (1 << j) <= m; ++c) {
                    if (i == 0 && j == 0)
                        continue;
                    if (i == 0) {
                        st[r][c][i][j] = max(st[r][c][i][j - 1], st[r][c + (1 << (j - 1))][i][j - 1]);
                    } else if (j == 0) {
                        st[r][c][i][j] = max(st[r][c][i - 1][j], st[r + (1 << (i - 1))][c][i - 1][j]);
                    } else {
                        st[r][c][i][j] = max({st[r][c][i - 1][j - 1], st[r + (1 << (i - 1))][c][i - 1][j - 1],
                                              st[r][c + (1 << (j - 1))][i - 1][j - 1],
                                              st[r + (1 << (i - 1))][c + (1 << (j - 1))][i - 1][j - 1]});
                    }
                }
            }
        }
    }

}


int query(int x1, int y1, int x2, int y2) {
    int dist1 = LOG[x2 - x1 + 1], dist2 = LOG[y2 - y1 + 1];
    return max({st[x1][y1][dist1][dist2], st[x2 - (1 << dist1) + 1][y1][dist1][dist2],
                st[x1][y2-(1<<dist2)+1][dist1][dist2], st[x2-(1<<dist1)+1][y2-(1<<dist2)+1][dist1][dist2]});
}

bool compute(int x1, int y1, int x2, int y2, int x) {
    return query(x1+x-1, y1+x-1, x2, y2)>=x;
}

int binarySearch(int x1, int y1, int x2, int y2) {
    int low = 0, high = min(x2 - x1 + 1, y2 - y1 + 1);
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (compute(x1, y1, x2, y2, mid)) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    precomputeLog();
    precomputeCache();
    precomputeST();

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        cout << binarySearch(x1, y1, x2, y2) << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}