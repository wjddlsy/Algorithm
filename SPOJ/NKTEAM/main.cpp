#include <iostream>
#include <vector>

using namespace std;

const int MAX = 500001;

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
            ret = max(ret, bit[r]);
        return ret;
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], delta);
    }
};

struct order {
    int one, two, three;
    bool operator < (const order &other) const {
        return one > other.one;
    }
};
int main() {
    int N;
    cin >> N;

    order a[MAX];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin>>x;
            if(i==0)
                a[x].one = N - j;
            if(i==1)
                a[x].two = N - j;
            else
                a[x].three = N - j;
        }
    }

    sort(a, a+N);
    FenwickTree ft(N);
    int ret = 0;
    for(int i=0; i<N; ++i) {
        int maxScore = ft.sum(a[i].two + 1);
        if(maxScore < a[i].three)
            ret++;
        ft.add(a[i].two, a[i].three);
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}