#include <iostream>

using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;

    /*
     * V <= (A-B) * (x-1) + A
     * answer is x-1;
     */

    if (B >= A)
        cout << -1;
    else
        cout << ((V - A) % (A - B) == 0 ? (V - A) / (A - B) + 1 : (V - A) / (A - B) + 2);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}