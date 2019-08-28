#include <iostream>
#include <vector>

using namespace std;


long long count(int n, int div) {
    long long ret=0;
    for(long long i=div; i<=n; i*=div) {
        ret+=n/i;
    }
    return ret;
}
int main() {
    int n, m;
    cin>>n>>m;
    // nCm = n! / m!(n-m)!
    long long two=0, five=0;
    two=count(n, 2) - count(m, 2) - count(n-m, 2);
    five=count(n, 5) - count(m, 5) - count(n-m, 5);

    cout<<min(two, five);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}