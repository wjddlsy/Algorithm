#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, B;
    cin>>N>>B;
    string ret;
    while(N) {
        int digit=N%B;
        if(digit<10)
            ret+=(digit+'0');
        else
            ret+=(digit-10+'A');
        N/=B;
    }
    reverse(ret.begin(), ret.end());
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}