#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, M;
    cin >> H >> M;
    if(M >= 45) {
        cout << H << " " << M - 45;
    } else {
        cout << (H + 24 - 1) % 24 << " " << (M + 60 - 45) % 60;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}