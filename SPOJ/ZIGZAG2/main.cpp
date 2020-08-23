#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &in:a) {
            cin >> in;
        }

        int m;
        cin >> m;
        vector<int> b(m);
        for (auto &in:b) {
            cin >> in;
        }

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}