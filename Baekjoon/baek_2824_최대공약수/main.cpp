#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<int, int> primeA;
    map<int, int> primeB;
    int n, m;
    cin>>n;
    for(int i=0; i<n; ++i) {
        int a; cin>>a;
        for(int j=2; j*j<=a; ++j) {
            while(a%j==0) {
                a/=j;
                primeA[j]++;
            }
        }
        if(a>1)
            primeA[a]++;
    }
    cin>>m;
    for(int i=0; i<m; ++i) {
        int b; cin>>b;
        for(int j=2; j*j<=b; ++j) {
            while(b%j==0) {
                b/=j;
                primeB[j]++;
            }
        }
        if(b>1)
            primeB[b]++;
    }
    long long ret=1;
    const long long mod=1000000000;
    bool flag=false;
    for (auto &common:primeA) {
        if(primeB[common.first]==0)
            continue;
        for (int i=0; i<min(primeA[common.first], primeB[common.first]); ++i) {
            ret*=common.first;
            if(ret>=mod) {
                flag=true;
                ret%=mod;
            }
        }
    }
    string s=to_string(ret);
    if(flag) {
        for(int i=s.size()+1; i<=9; ++i)
            cout<<'0';
    }
    cout<<s;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}