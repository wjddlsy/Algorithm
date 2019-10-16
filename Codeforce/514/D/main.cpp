#include <iostream>
#include <vector>

using namespace std;

int st[5][100001][20], log[100001];
int n, m, k;

void computeLog() {
    log[1] = 0;
    for(int i=2; i<n; ++i) {
        log[i] = log[i/2] + 1;
    }
}

int main() {
    cin>>n>>m>>k;
    vector<vector<int>> droids(n);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            int a; cin>>a;
            droids[i].emplace_back(a);
        }
    }

    // sparse table
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            st[i][j][0] = droids[j][i];
        }
    }

    for(int mm=0; mm<m; ++mm) {
        for(int i=0; i<n; ++i) {
            for(int j=1; i+(1<<j)<=n; ++j) {
                st[mm][i][j] = max(st[mm][i][j-1], st[mm][i+(1<<j)][j-1]);
            }
        }
    }

    computeLog();

    int left=0, right=0;

    while(right<n) {
        for(int i=0; i<m; ++i) {
            int dist = right-left+1;
            int maximum = max(st[i][left][dist], st[i][right-(1<<dist)][dist]);
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}