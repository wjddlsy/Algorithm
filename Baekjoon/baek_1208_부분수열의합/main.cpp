#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
vector<int> perm;

void solve(int pos, int end, int sum, vector<int> &p) {
    if (pos == end) {
        p.emplace_back(sum);
        return;
    }
    solve(pos + 1, end, sum + perm[pos], p);
    solve(pos + 1, end, sum, p);
}

int main() {
    cin >> N >> S;
    perm.resize(N);
    for (auto &p:perm) {
        cin >> p;
    }
    vector<int> left, right;
    solve(0, N / 2, 0, left);
    solve(N / 2, N, 0, right);
    sort(right.begin(), right.end());

    long long ret = 0;
    for (auto &val:left) {
        int target = S - val;
        auto hi = upper_bound(right.begin(), right.end(), target);
        auto low = lower_bound(right.begin(), right.end(), target);
        ret += hi - low;
    }
    cout << (S == 0 ? ret - 1 : ret);
    return 0;
}