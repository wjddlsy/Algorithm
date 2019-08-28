#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    cin>>N;
    map<int, int> primes;
    int tmp=N;
    for(int i=2; i*i<=N; ++i) {
        while(tmp%i==0) {
            primes[i]++;
            tmp/=i;
        }
    }
    if(tmp>1)
        primes[tmp]++;

    for(auto &p:primes) {
        while(p.second--)
            cout<<p.first<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}