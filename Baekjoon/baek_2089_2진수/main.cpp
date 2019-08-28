#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    string ret;

    if(n==0) {
        cout<<0;
        return 0;
    }
    while(n) {
        int next=0;
        if(n > 0) {
            next=n/(-2);
            ret+=(n-next*(-2)+'0');
        }
        else {
            next=n%(-2)==0?n/(-2):n/(-2)+1;
            ret+=(n-next*(-2)+'0');
        }
        n=next;
    }
    reverse(ret.begin(), ret.end());
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}