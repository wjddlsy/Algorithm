#include <iostream>
#include <vector>

using namespace std;

const long long MOD=1000000000;

int main() {
    int N, K;
    cin>>N>>K;
    long long cache[201][201];
    for(int i=0; i<=N; ++i) {
        cache[i][1]=1;
        for(int j=0; j<=i; ++j) {
            for(int k=2; k<=K; ++k)
                cache[i][k]=(cache[j][K-k]+cache[j][k])%MOD;
        }
    }
    cout<<cache[N][K]%MOD;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}