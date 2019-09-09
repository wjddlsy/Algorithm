#include <iostream>
#include <cstring>
using namespace std;

int N;
int cache[31];

int solve(int n) {
    if(n<=0)
        return 0;
    int &ret = cache[n];
    if(ret!=-1)
        return ret;
    if(n==1 || n==2) {
        ret = n;
    }
    else
        ret = 0;
    ret += solve(n-1) + solve(n-2) * 2;
    return ret;
}
int main() {
    cin>>N;
    memset(cache, -1, sizeof(cache));
    solve(N);
    cache[0] = 1;

    int ret = 0;
    if(N%2==0)
        ret = (cache[N] - cache[N/2] - cache[N/2-1]*2)/2 + cache[N/2] + cache[N/2-1]*2;
    else
        ret = (cache[N] - cache[N/2]) / 2 + cache[N/2];
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}