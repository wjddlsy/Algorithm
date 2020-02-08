#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);

    for (auto &num:nums) {
        cin >> num;
    }

    vector<int> m(100001);

    for (auto &num:nums) {
        m[num]++;
    }

    int ans = 0;
    for (auto &num:nums) {
        if (M - num >= 0 && M - num <= 100000 && m[M - num]) {
            ans++;
        }
    }

    cout << ans / 2;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
