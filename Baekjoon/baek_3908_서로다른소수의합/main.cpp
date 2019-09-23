#include <iostream>
#include <vector>

using namespace std;

bool isPrime[1121];
int cache[500][1121][15];
vector<int> primes;

void eratos(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i=2; i*i<=n; ++i) {
        if(!isPrime[i])
            continue;
        for(int j=2*i; j<=n; j+=i) {
            isPrime[j]=false;
        }
    }
    for(int i=2; i<=n; ++i) {
        if(isPrime[i])
            primes.emplace_back(i);
    }
}

int solve(int here, int remain, int k) {
    if(remain==0 && k==0)
        return 1;
    if(remain==0 || k==0)
        return 0;
    if(here==primes.size())
        return 0;
    int &ret = cache[here][remain][k];
    if(ret!=-1) {
        return ret;
    }
    ret = solve(here+1, remain, k);
    if(remain-primes[here]>=0)
        ret += solve(here+1, remain-primes[here], k-1);
    return ret;
}

int main() {
    int T;
    cin>>T;
    eratos(1120);
    memset(cache, -1, sizeof(cache));
    while(T--) {
        int n, k;
        cin>>n>>k;
        cout<<solve(0, n, k)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}