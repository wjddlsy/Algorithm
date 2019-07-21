#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, P, V;
    int t=1;
    while (true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) {
            break;
        }
        cout<<"Case "<<t<<": "<<(V/P)*L+min(L, V%P)<<'\n';
        t++;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}