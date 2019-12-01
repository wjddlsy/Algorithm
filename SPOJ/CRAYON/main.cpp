#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000005;
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

int main() {
    int N;
    cin >> N;

    vector<char> type(N);
    vector<int> l(N), r(N), who(N), c(N);
    FenwickTree ft1(MAX), ft2(MAX);
    vector<int> data;

    int id = 0;
    for (int i = 0; i < N; ++i) {
        cin >> type[i];
        if (type[i] == 'C') {
            cin >> c[i];
        } else if (type[i] == 'D') {
            cin >> l[i] >> r[i];
            who[++id] = i;
        } else {
            cin >> l[i] >> r[i];
        }
    }

    // compress data
    data = vector<int>(l.begin(), l.end());
    data.insert(data.end(), r.begin(), r.end());
    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());

    for (int i = 0; i < N; ++i) {
        if (type[i] != 'C') {
            l[i] = lower_bound(data.begin(), data.end(), l[i]) - data.begin();
            r[i] = lower_bound(data.begin(), data.end(), r[i]) - data.begin();
        }
    }

    for (int i = 0; i < N; ++i) {
        if (type[i] == 'D') {
            ft1.add(l[i], 1);
            ft2.add(r[i], 1);
        } else if (type[i] == 'C') {
            int _id = who[c[i]];
            ft1.add(l[_id], -1);
            ft2.add(r[_id], -1);
        } else {
            cout << ft1.sum(r[i]) - ft2.sum(l[i] - 1) << '\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}