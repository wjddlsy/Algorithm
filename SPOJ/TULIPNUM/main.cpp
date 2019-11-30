#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": " << '\n';
        int N, Q;
        cin >> N >> Q;
        vector<int> arr(N);
        for (auto &a:arr) {
            cin >> a;
        }
        vector<int> presum(N, 0);
        for (auto &a:arr) {
            presum[a] = 1;
        }
        for (int i = 1; i < N; ++i) {
            presum[i] += presum[i - 1];
        }
        while (Q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << presum[arr[r]] - (arr[l] == 0 ? 0 : presum[arr[l] - 1]) << '\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}