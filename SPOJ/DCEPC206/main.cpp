#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10e6 + 1;

struct FenwickTree {
    vector<long long> bit;
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    long long sum(int idx) {
        long long ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        FenwickTree ft(MAX);

        long long ret = 0;
        for(int i=0; i<N; ++i) {
            int x;
            cin >> x;
            ret += ft.sum(x - 1);
            ft.add(x, x);
        }

        cout << ret << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
