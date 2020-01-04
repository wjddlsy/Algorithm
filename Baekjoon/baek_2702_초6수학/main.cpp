#include <iostream>

using namespace std;

int gcd(int a, int b) {

    return b ? gcd(b, a%b) : a;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        cout << g * (a / g) * (b / g) << " " << g << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}