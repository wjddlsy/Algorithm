#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;
const int MAX = 200001;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

vector<long long> fact;

void computeFactorial() {
    fact.resize(MAX);
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    computeFactorial();
    while (t--) {
        int n;
        cin >> n;
        vector<int> perm(n);
        for (auto &p:perm) {
            cin >> p;
        }
        FenwickTree ft(n);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int x = ft.sum(perm[i] - 1);
            ret = (ret + (perm[i] - x - 1) * fact[n - i - 1] % mod) % mod;
            ft.add(perm[i] - 1, 1);
        }
        cout << ret + 1 << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}