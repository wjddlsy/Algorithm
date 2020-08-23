#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i:a) {
        cin >> i;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}