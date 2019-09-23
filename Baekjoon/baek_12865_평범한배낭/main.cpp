#include <iostream>
#include <cstring>

using namespace std;

int N, K, weights[101], values[101];
int cache[101][100001];

int solve(int here, int remain) {
    if(here==N)
        return 0;
    int &ret=cache[here][remain];
    if(ret!=-1)
        return ret;
    ret = solve(here+1, remain);
    if(remain - weights[here]>=0)
        ret = max(ret, solve(here+1, remain-weights[here])+values[here]);
    return ret;
}

int main() {
    cin>>N>>K;
    for(int i=0; i<N; ++i) {
        cin>>weights[i]>>values[i];
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, K);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}