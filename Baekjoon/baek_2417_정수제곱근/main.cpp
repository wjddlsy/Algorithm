#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    cin>>n;
    unsigned long long lo=0, hi=(1ull<<32);
    while(lo<hi) {
        unsigned long long mid=(lo+hi)/2;
        if(mid*mid>=n) {
            hi=mid;
        } else {
            lo=mid+1;

        }
    }
    cout<<lo;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}