#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
        vector<long long> bit;
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
            for(; r>=0; r = (r&(r+1))-1)
                ret+=bit[r];
            return ret;
        }

        void add(int idx, int delta) {
            for(; idx<n; idx=idx|(idx+1))
                bit[idx] += delta;
        }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t) {
        cout << "Case " << t << ":" << '\n';
        int n, q;
        cin>>n>>q;
        vector<int> sacks(n);
        for(auto &sack:sacks) {
            cin>>sack;
        }
        FenwickTree ft(sacks);
        while(q--) {
            int oper, a, b;
            cin>>oper;
            if(oper==1) {
                cin>> a;
                cout << sacks[a] << '\n';
                ft.add(a, -sacks[a]);
                sacks[a] = 0;
            } else if(oper==2) {
                cin >> a >> b;
                ft.add(a, b);
                sacks[a] += b;
            } else {
                cin>>a>>b;
                cout << ft.sum(b) - ft.sum(a-1) << '\n';
            }
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}