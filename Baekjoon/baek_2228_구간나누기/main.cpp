#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// n까지 봤을 때 구간이 m개일 때 최댓값
int cache[101][101];
int psum[101], arr[101];
const int INF = 10000000;

int solve(int n, int m) {
    if(m==0)
        return 0;
    if(n<=0)
        return -INF;
    int& ret=cache[n][m];
    if(ret!=-1)
        return ret;
    ret = -INF;
    // n 번째가 구간에 안속할 때
    ret = max(ret, solve(n-1, m));
    // 내가 구간에 속할때
    for(int i=1; i<=n; ++i) {
        // i~n까지 구간에 속하는거
        ret = max(ret, psum[n]-psum[i-1]+solve(i-2, m-1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    psum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        psum[i] = psum[i-1] + a;
        arr[i] = a;
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(N, M);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}