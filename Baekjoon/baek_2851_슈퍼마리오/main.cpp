#include <iostream>
#include "vector"

using namespace std;

int main() {
    int sum = 0, ret = 0;

    for(int i=0; i<10; ++i) {
        int n;
        cin >> n;
        sum += n;
        ret = abs(sum-100) <= abs(ret - 100) ? sum : ret;
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
