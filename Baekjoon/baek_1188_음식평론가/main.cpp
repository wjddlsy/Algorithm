#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
int main() {
    int N, M;
    cin >> N >> M;

    cout << M - gcd(N, M);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
