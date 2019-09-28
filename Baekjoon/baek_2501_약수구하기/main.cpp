#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin>>N>>K;

    int ans = 0;
    for(int i=1; i<=N; ++i) {
        if(N%i==0) {
            K--;
        }
        if(K==0) {
            ans = i;
            break;
        }
    }
    cout << ans;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}