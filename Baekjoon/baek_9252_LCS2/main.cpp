#include <iostream>
#include <cstring>

using namespace std;


string a, b;
int cache[1002][1002];

int main() {
    cin >> a >> b;
    int a_size = a.size(), b_size = b.size();

    a.insert(a.begin(), '0');
    b.insert(b.begin(), '0');

    for (int i = 1; i <= a_size; ++i) {
        for (int j = 1; j <= b_size; ++j) {
            if (a[i] == b[j])
                cache[i][j] = cache[i - 1][j - 1] + 1;
            else {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }
    int len = cache[a_size][b_size];
    cout << len;
    solve(a_size, b_size, len);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}