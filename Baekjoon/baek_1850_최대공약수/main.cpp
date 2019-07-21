#include <iostream>
#include <math.h>
using namespace std;


#define MAX_N 10000001

long long gcd(long long  p, long long q){
    if(q==0) return p;
    return gcd(q, p%q);
}


int main() {
    long long a, b;
    cin >> a >> b;
    for(int i=1; i<=gcd(a,b); ++i){
        cout << 1;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}