#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        cout << 1;
    }
    for (int i = 0; i < k - 1; ++i) {
        cout << 0;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}