#include <iostream>
#include <vector>

using namespace std;


int A, B, C, N;

bool solve() {
    int a = N / A, b = N / B, c = N / C;

    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                if ( N - i * A - j * B - k * C == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> A >> B >> C >> N;

    cout << (solve() ? 1 : 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}