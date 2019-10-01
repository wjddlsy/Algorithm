#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int main() {
    int N;
    cin >> N;
    vector<int> lis = {-INF};
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (lis.back() < x) {
            lis.emplace_back(x);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }
    cout << N - lis.size() + 1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}