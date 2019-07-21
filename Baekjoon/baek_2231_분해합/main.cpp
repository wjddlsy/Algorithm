#include <iostream>

using namespace std;

int main() {
    int n, tmp, digit=1;
    cin>>n;
    tmp=n;
    while(tmp/10){
        digit++;
        tmp/=10;
    }

    int start=n-9*digit;
    for(int i=start; i<=n; ++i){
        tmp=i, digit=i;
        while(tmp){
            if(digit>n)
                break;
            digit+=tmp%10;
            tmp/=10;
        }
        if(digit==n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}