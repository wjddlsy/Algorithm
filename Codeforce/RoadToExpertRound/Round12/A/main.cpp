#include <iostream>

using namespace std;

int main() {
    long long l, r;
    cin>>l>>r;
    long long diff=r-l;
    if(diff<=1)
        cout<<-1;
    else if(diff==2) {
        if(l%2==0) {
            cout<<l<<" "<<l+1<<" "<<r;
        }
        else
            cout<<-1;
    }
    else {
        if(l%2==0) {
            cout<<l<<" "<<l+1<<" "<<l+2;

        }
        else {
            cout<<l+1<<" "<<l+2<<" "<<l+3;
        }
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}