#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for(auto &i:X) {
        cin >> i;
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; ++i) {
        int oper;
        cin >> oper;
        if(oper == 0) {
            int a, b, c;
            cin >> a >> b >> c;

        } else {
            int a, b;
            cin >> a >> b;
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}