#include <iostream>
#include <vector>

using namespace std;

int main() {

    long long A, B, C;
    cin >> A >> B >> C;

    /*
     * C*x >= A + B*x
     * x >= A / (C-B)
     */

    if (B >= C)
        cout << -1;
    else
        cout << A / (C - B) + 1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}