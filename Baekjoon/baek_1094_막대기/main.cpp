#include <iostream>

using namespace std;

int main() {
    int x, sum=64, m=64, cnt=0;
    cin>>x;
    while(x>0){
        if(m>x){
            m/=2;
        }
        else {
            cnt++;
            x-=m;
        }
    }
    cout << cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}