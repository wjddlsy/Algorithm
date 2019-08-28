#include <iostream>

using namespace std;

int cache[1001][10];
int main() {
    int n;
    cin>>n;

    for(int i=0; i<=9; ++i) {
        cache[1][i]=1;
    }
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<=9; ++j) {
            for(int k=j; k<=9; ++k) {
                cache[i][j]=(cache[i][j]+cache[i-1][k])%10007;
            }
        }
    }

    int ret=0;
    for(int i=0; i<=9; ++i) {
        ret=(ret+cache[n][i])%10007;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}