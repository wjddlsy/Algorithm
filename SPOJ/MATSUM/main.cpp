#include <iostream>
#include <vector>

using namespace std;


struct FenwickTree {
    vector<vector<int>> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit = vector<vector<int>>(n, vector<int>(n, 0));
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    int sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < n; j = j | (j + 1))
                bit[i][j] += delta;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        FenwickTree ft(N);
        string cmd;
        while(cin>>cmd) {
            if (cmd == "SET") {
                int x, y, num;
                cin>>x>>y>>num;
                int origin = ft.sum(x, y, x, y);
                ft.add(x, y, num);
                ft.add(x, y, -origin);
            } else if (cmd == "SUM") {
                int x1, y1, x2, y2;
                cin>>x1>>y1>>x2>>y2;
                cout<<ft.sum(x1, y1, x2, y2)<<'\n';
            } else
                break;
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}