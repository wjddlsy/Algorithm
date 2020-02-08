#include <iostream>

using namespace std;

int main() {
    int C, R, K;
    cin >> C >> R >> K;

    // total

    // R*C, R-2 * C-2, ...

    // R*C + (R-2) * (C-2)

    int x = 1, y = 1;

    while(R && C) {
        if(K <= R*C) {
            break;
        }
        K -= R*C;
        R -= 2;
        C -= 2;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
