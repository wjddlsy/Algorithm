#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    return b?gcd(b, a%b):a;
}

int main() {
    int n;
    cin>>n;
    vector<long long> a(n);

    for(auto &aa:a) {
        cin>>aa;
    }

    long long ret=a[0];
    for(auto &aa:a) {
        ret=gcd(ret, aa);
    }

    long long cnt=0;
    for(long long i=1; i*i<=ret; ++i) {
        if(i*i==ret) {
            cnt++;
            break;
        }
        if(ret%i==0)
            cnt+=2;
    }
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}