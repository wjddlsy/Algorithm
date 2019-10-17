#include <iostream>
#include <vector>

using namespace std;

int st[5][100001][20], log[100001];
int n, m, k;

void computeLog() {
    log[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log[i] = log[i / 2] + 1;
    }
}

    int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<vector<int>> droids(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            droids[i].emplace_back(a);
        }
    }

    // sparse table
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            st[i][j][0] = droids[j][i];
        }
    }

    for (int mm = 0; mm < m; ++mm) {
        for (int j = 1; j <20; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[mm][i][j] = max(st[mm][i][j - 1], st[mm][i + (1 << (j-1))][j - 1]);
            }
        }
    }

    computeLog();

    int left = 0, right = 0, ret = 0;
    vector<int> info(m, 0);

    while (left < n && right < n) {
        int sum = 0;
        vector<int> tmp(m, 0);
        for (int i = 0; i < m; ++i) {
            int dist = log[right - left + 1];
            int maximum = max(st[i][left][dist], st[i][right - (1 << dist) + 1][dist]);
            sum += maximum;
            tmp[i] = maximum;
        }
        if(sum <=k ) {
            if(ret <= right-left) {
                info = tmp;
                ret = right-left;
            }
            right++;
        }
        else {
            left++;
            if(left > right)
                right = left;
        }

    }

    for(auto &i:info) {
        cout << i << " ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}