#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin>>n;
    long long ret=0;
    if(n%2==0){
        ret=n/2;
    }
    else {
        long long even=n-1;
        ret+=even/2;
        ret-=n;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}