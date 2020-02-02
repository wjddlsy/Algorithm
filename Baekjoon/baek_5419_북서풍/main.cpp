#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a):FenwickTree(a.size()) {
        for(size_t i=0; i<a.size(); ++i) {
            add(i, a[i]);
        }
    }

    int sum(int r) {
        int ret = 0;
        for(; r>=0; r = (r & (r+1)) - 1)
            ret+=bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, int delta) {
        for(; idx<n; idx = idx | (idx+1))
            bit[idx] += delta;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> islands;
        vector<int> xpos, ypos;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            islands.emplace_back(x, y);
            xpos.emplace_back(x);
            ypos.emplace_back(y);
        }

        sort(xpos.begin(), xpos.end());
        sort(ypos.begin(), ypos.end());
        xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
        ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

        for(auto &island:islands) {
            island.first = lower_bound(xpos.begin(), xpos.end(), island.first) - xpos.begin();
            island.second = lower_bound(ypos.begin(), ypos.end(), island.second) - ypos.begin();
        }

        sort(islands.begin(), islands.end(),
             [](const pair<int, int> a, const pair<int, int> b) {
                // x좌표 감소 이러면 서쪽에 있는게 먼저옴
                if(a.first == b.first)
                    return a.second > b.second;
                return a.first < b.first;
             });

        long long ans = 0;
        FenwickTree ft(n);

        for(auto &island:islands) {
            ans += ft.sum(island.second, n - 1);
            ft.add(island.second, 1);
        }

        cout << ans << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
