#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int calorie[5001], price[5001], n;
int cache[10001];

int solve(int remain) {
    int &ret=cache[remain];
    if(ret!=-1)
        return ret;
    ret = 0;
    for(int i=0; i<n; ++i) {
        if(remain-price[i]>=0)
            ret = max(ret, solve(remain-price[i])+calorie[i]);
    }
    return ret;
}
int main() {
    int c;
    double m, p;
    while(cin>>n>>m) {
        if(n==0)
            break;
        for (int i = 0; i < n; ++i) {
            cin >> c >> p;
            calorie[i] = c;
            price[i] = (int) (p * 100 + 0.5);
        }
        memset(cache, -1, sizeof(cache));
        cout << solve((int) (m * 100 + 0.5)) << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}