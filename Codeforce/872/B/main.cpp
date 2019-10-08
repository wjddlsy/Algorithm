#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int st[100001][20], log[100001];

int getMin(int l, int r) {
    int j = log[r - l + 1];
    return min(st[l][j], st[r - (1 << j)+1][j]);
}

int main() {
    int n, k, minimum = 1000000000, maximum = -1000000000;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &a:arr) {
        cin >> a;
        minimum = min(minimum, a);
        maximum = max(maximum, a);
    }

    log[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log[i] = log[i / 2] + 1;
    }

    for (int i = 0; i < n; ++i) {
        st[i][0] = arr[i];
    }

    for (int j = 1; j <= log[n] + 1; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    if (k == 1)
        cout << minimum;
    else if (k == 2) {
        int ret = -1000000000;
        for (int mid=0; mid<n-1; ++mid) {
            ret = max({ret, getMin(0, mid), getMin(mid+1, n-1)});
        }
        cout << ret;
    } else {
        cout << maximum;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}