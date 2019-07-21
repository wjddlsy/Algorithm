#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n; cin>>n;
    int a, b;
    if(n==3){
        a=1;
        b=2;
    }
    else {
        for (int i = 1; i <= n / 2; ++i) {
            if(i==n-i)
                break;
            int g = gcd(i, n - i);
            if (g == 1) {
                a = i;
                b = n - i;
            }
        }
    }
    cout<<a<<" "<<b;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}