#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int gcd(int a, int b) {
    return b?gcd(b, a%b):b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;

    map<int, int> primes;
    vector<map<int, int>> numbers(N);
    for(int i=0; i<N; ++i) {
        int n;
        cin>>n;
        for(int d=2; d*d<=n; ++d) {
            while(n) {
                if(n%d!=0)
                    break;
                primes[d]++;
                numbers[i][d]++;
                n/=d;
            }
        }
        if(n>1) {
            primes[n]++;
            numbers[i][n]++;
        }
    }
    map<int, int> ret;
    int cnt=0, greatest=1;
    for(auto &prime:primes) {
        ret[prime.first]=prime.second/N;
    }

    for(auto &number:numbers) {
        for(auto &r:ret) {
            if(number[r.first]>r.second)
                continue;
            cnt+=abs(number[r.first]-r.second);
        }
    }

    for(auto &r:ret) {
        for(int i=0; i<r.second; ++i) {
            greatest*=r.first;
        }
    }

    cout<<greatest<<" "<<cnt;
    return 0;
}