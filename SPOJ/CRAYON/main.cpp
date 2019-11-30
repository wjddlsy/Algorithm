#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    vector<int> range_bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
        range_bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r] >= 2 ? 1 : bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void range_add(int l, int r, int delta) {
        add(l, delta);
        add(r+1, delta);
    }
};

int main() {
    int N;
    cin >> N;
    FenwickTree ft(N);

    for(int i=0; i<N; ++i) {
        char oper;
        cin >> oper;
        if (oper == 'D') {
            int l, r;
            cin>>l>>r;
            cout << ft.add()
        } else if (oper == 'Q') {
            int l, r;
            cin>>l>>r;

        } else {

        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}