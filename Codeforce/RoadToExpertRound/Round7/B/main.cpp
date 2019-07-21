#include <iostream>
#include <vector>

using namespace std;

long long cnt=0;
long long gcd(long long a, long long b){
    if(a>b) swap(a, b);
    if(a==0) return b;
    cnt+=(b/a);
    return gcd(b%a, a);
}
int main() {
    long long a, b;
    cin>>a>>b;
    gcd(a, b);
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}