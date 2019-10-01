#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[501][501];

int main() {
    int n, m;

    cin >> n;
    vector<int> a(n);
    cin >> m;
    vector<int> b(m);

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if(a[i] == b[j])
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}