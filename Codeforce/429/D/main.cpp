#include <iostream>
#include <vector>

using namespace std;

/*
 * (r-l+1)/k 번 보다 많이 발생한 x 중 가장 작은 x를 찾아라.
 * 만약 그러한 x가 없다면 -1을 출력하자.
 * https://codeforces.com/blog/entry/53943?locale=en
 * divide and conquer.
 *
 */

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &i:a) {
        cin >> i;
    }

    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}