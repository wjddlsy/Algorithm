#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lis = {-987654321};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (lis.back() < x) {
            lis.emplace_back(x);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }
    cout << n - lis.size() + 1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
