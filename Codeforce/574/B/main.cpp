#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, k;
    cin>>n>>k;
    long long right=(n+k)*2;

    for(long long a=0; a*(3+a)<=right; ++a) {
        if(a*(3+a)==right) {
            cout<<n-a;
            break;
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}