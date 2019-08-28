#include <iostream>
#include <vector>

using namespace std;

int cache[1001];

int main() {
    int n;
    cin>>n;
    cache[1]=1; cache[2]=3;
    for(int i=3; i<=n; ++i) {
        cache[i]=cache[i-1]%10007 + (cache[i-2]*2)%10007;
    }
    cout<<cache[n]%10007;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}