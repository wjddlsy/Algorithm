#include <iostream>
#include <math.h>

using namespace std;

long long gcd(long long p, long long q){
    if(q==0)
        return p;
    return gcd(q, p%q);
}

long long lcm(long long a, long long b){
    long long g=gcd(a, b);
    return (g*(a/g) * (b/g));
}

int find_max(long long a, long long b){
    if(a==1)
        return b;
    long long m = ceil((double)b/a);
    long long new_b = lcm(m, b);
    long long new_a = a*new_b/b - new_b/m;

    // 기약분수로 만들기
    long long g=gcd(new_a, new_b);
    new_a=new_a/g; new_b=new_b/g;

    return find_max(new_a, new_b);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<find_max(a,b) << endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}