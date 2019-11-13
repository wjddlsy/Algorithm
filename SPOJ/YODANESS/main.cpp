#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        map<string, int> m;
        vector<pair<int, int>> order;
        for(int i=1; i<=n; ++i) {
            string s;
            cin>>s;
            m[s] = i;
        }

        for(int i=1; i<=n; ++i) {
            string s;
            cin>>s;
            order.emplace_back(m[s], i);
        }

        int ret = 0;
        FenwickTree ft(n+1);
        sort(order.begin(), order.end(), greater<>());
        for(auto &o:order) {
            int val = o.first, idx = o.second;
            ret += ft.sum(idx);
            ft.add(idx, 1);
        }
        cout << ret << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}