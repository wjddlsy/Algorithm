#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int a, b;
    cin>>a>>b; //a: 최대공약수 b: 최소공배수
    // c 와 d가 있다고 할 때
    // (c / a) * (d / a) * a = b 가 되는 c와 d를 구하시오
    int c, d, sum=987654321;
    for(int candC=a; candC<=b; candC+=a) {
        int divC=candC/a;
        if((b/a)%divC==0) {
            int divD=(b/a)/divC, candD=divD*a;
            if(gcd(divC, divD)==1) {
                if(candC+candD<sum) {
                    sum=candC+candD;
                    c=candC;
                    d=candD;
                }
            }
        }
    }
    cout<<c<<" "<<d;
    //6 180std::cout << "Hello, World!" << std::endl;
    return 0;
}