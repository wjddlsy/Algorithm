#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int minValue = 1000000, maxValue = -1000000;
    for(int i=0; i<N; ++i) {
        int a; cin >> a;
        minValue = min(minValue, a);
        maxValue = max(maxValue, a);
    }
    cout << minValue << " " << maxValue;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}