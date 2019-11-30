#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
void update(vector<long long> &v, int idx, long long x) {
    while(idx>0) {
        v[idx] += x;
        idx -= idx&-idx;
    }
}

long long sum(vector<long long> &v, int idx) {
    long long ret = 0;
    while(idx<=n) {
        ret += v[idx];
        idx += idx&-idx;
    }
    return ret;
}

int main() {
    cin >> n;

    vector<long long> t1(n + 3, 0), f2(n + 3, 0);

    long long ret = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        update(t1, x, 1);
        int y = sum(t1, x+1);
        update(f2, x, y);
        ret += sum(f2, x + 1);
    }

    cout << ret;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}