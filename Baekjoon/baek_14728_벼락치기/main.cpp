#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int times[101], score[101], N, T;
int cache[101][10001];

int solve(int here, int remain) {
    if(here==N)
        return 0;
    int &ret=cache[here][remain];
    if(ret!=-1)
        return ret;
    ret = solve(here+1, remain);
    if(remain-times[here]>=0)
        ret = max(ret, solve(here+1, remain-times[here])+score[here]);
    return ret;
}
int main() {
    cin>>N>>T;
    for(int i=0; i<N; ++i) {
        cin>>times[i]>>score[i];
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, T);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}