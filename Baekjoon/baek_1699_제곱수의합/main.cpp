#include <iostream>
#include <vector>

using namespace std;

int cache[100001];
int main() {
    int N;
    cin>>N;
    cache[1]=1;
    for(int i=2; i<=N; ++i) {
        cache[i]=i;
        for(int j=1; j*j<=i; ++j) {
            cache[i]=min(cache[i], 1+cache[i-j*j]);
        }
    }
    cout<<cache[N];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}