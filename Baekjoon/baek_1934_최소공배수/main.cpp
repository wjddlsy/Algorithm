#include <iostream>

using namespace std;

long long gcd(long long p, long long q){
    if(q==0) return p;
    return gcd(q, p%q);
}

long long lcd(long long a, long long b){
    int g=gcd(a, b);
    return g*(a/g)*(b/g);
}

int main() {

    long long a, b;
    cin >> a >> b;
    cout << gcd(a,b) << '\n' << lcd(a, b) ;

    return 0;
}