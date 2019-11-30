#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (auto &a:arr) {
        cin >> a;
    }

    while (Q--) {
        int oper;
        cin >> oper;
        if (oper == 1) {
            int x, i;
            cin >> x >> i;
        } else {
            string Op;
            int i1, i2;
            cin >> Op >> i1 >> i2;
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}