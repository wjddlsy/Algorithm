#include <iostream>
#include <cstring>

using namespace std;


string a, b;
int cache[1002][1002];

//int solve(int i, int j) {
//    if (i == -1 || j == -1) {
//        return 0;
//    }
//    int &ret = cache[i][j];
//    if (ret != -1)
//        return ret;
//    ret = 0;
//    if (a[i] == b[j]) {
//        ret = max(ret, solve(i - 1, j - 1) + 1);
//    } else {
//        ret = max(solve(i - 1, j), solve(i, j - 1));
//    }
//    return ret;
//}

int main() {
    cin >> a >> b;
    //memset(cache, -1, sizeof(cache));
    //cout << solve(a.size() - 1, b.size() - 1);
    int a_size = a.size(), b_size = b.size();
    a.insert(a.begin(), '0');
    b.insert(b.begin(), '0');

    for(int i=1; i<=a_size; ++i) {
        for(int j=1; j<=b_size; ++j) {
            if(a[i]==b[j])
                cache[i][j] = cache[i-1][j-1]+1;
            else {
                cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
            }
        }
    }
    cout << cache[a_size][b_size];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}