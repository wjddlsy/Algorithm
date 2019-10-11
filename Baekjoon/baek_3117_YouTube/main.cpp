#include <iostream>
#include <vector>

using namespace std;

int st[100001][32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    m--;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= k; ++i) {
        cin >> st[i][0];
    }

    for (int j = 1; j < 32; ++j) {
        for (int i = 1; i <= k; ++i) {
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
    }

    for(int i=1; i<=n; ++i) {
        int x = arr[i];
        int mm = m;
        for (int j=31; j>=0; --j) {
            if((1<<j) <= mm) {
                mm-=(1<<j);
                x = st[x][j];
            }
        }
        cout << x << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}