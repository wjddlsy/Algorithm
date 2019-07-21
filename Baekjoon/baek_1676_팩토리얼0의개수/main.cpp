#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[2]={0};
    for(int i=1; i<=n; ++i){
        int tmp=i;
        while(tmp%2==0){
            a[0]++;
            tmp/=2;
        }
        while(tmp%5==0){
            a[1]++;
            tmp/=5;
        }
    }

    cout<<min(a[0],a[1]);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}