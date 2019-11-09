#include <iostream>
#include <vector>

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
    int num = 1;
    while (true) {
        int N;
        cin >> N;
        if (N == 0)
            break;
        cout << "Case " << num << ":" << endl;
        vector<int> potmeters(N);
        for (auto &potmeter:potmeters) {
            cin >> potmeter;
        }
        FenwickTree ft(potmeters);
        while (true) {
            string s;
            cin >> s;
            if (s == "END")
                break;
            int a, b;
            cin >> a >> b;
            if (s == "S") {
                a--;
                ft.add(a, -potmeters[a]);
                ft.add(a, b);
                potmeters[a] = b;
            } else {
                a--; b--;
                cout << ft.sum(b) - ft.sum(a-1)<< endl;
            }
        }
        num++;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}