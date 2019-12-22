#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cout << "Case #" << t << ": ";
        int A, B;
        cin >> A >> B;
        cout << A << " + " << B << " = ";
        cout << A + B << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}

