#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool decision(long long k, long long N) {
    long long n=k*(k+1)/2;
    return n>N;
}

long long optimize(long long N) {
    long long lo=1, hi=sqrt(N+1)*2;
    while(lo<hi) {
        long long mid=(lo+hi)/2;
        if(decision(mid, N)) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    return lo-1;
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        long long N;
        cin>>N;
        cout<<optimize(N)<<'\n';
    }
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}