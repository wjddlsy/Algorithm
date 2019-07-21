#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const long long mod=998244353;

long long p(int n) {
    long long ret=1;
    for(int i=0; i<n; ++i) {
        ret=(ret*10)%mod;
    }
    return ret;
}
int main() {
    int n;
    cin>>n;
    long long ret=0;
    for(int i=0; i<n; ++i) {
        string s; cin>>s;
        long long conv=0;
        for(int j=0; j<s.size(); ++j) {
            conv+=((s[s.size()-1-j]-'0')*p(j*2+1))%mod;
            conv+=((s[s.size()-1-j]-'0')*p(j*2))%mod;
        }
        ret=(ret+(conv*n)%mod)%mod;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}