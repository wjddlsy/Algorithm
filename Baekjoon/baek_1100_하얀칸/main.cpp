#include <iostream>

using namespace std;


int main() {
    const int n = 8;

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char b;
            cin >> b;
            if (i % 2 == 0 and j % 2 == 0 and b == 'F') {
                ret++;
            } else if (i % 2 == 1 and j % 2 == 1 and b == 'F') {
                ret++;
            }
        }
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
