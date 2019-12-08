#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10e5 + 1, MAX_K = 10 + 1;
long long bit[MAX_K][MAX_N];
int n, k;

long long sum(int y, int x) {
    long long ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        ret += bit[y][i];
    }
    return ret;
}

void add(int y, int x, long long delta) {
    for (int i = x; i <= n; i = i | (i + 1)) {
        bit[y][i] += delta;
    }
}

int main() {
    cin >> n >> k;
    //long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        add(0, a, 1);
        for (int j = 1; j <= k; ++j) {
            long long query = sum(j - 1, a - 1);
            add(j, a, query);
        }
    }
    cout << sum(k, n);

    return 0;
}