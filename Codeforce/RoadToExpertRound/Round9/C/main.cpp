#include <iostream>
#include <vector>
using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int> a(n+1, 0), b(n+1, 0);

    for(int i=1; i<=n; ++i){
        int in;
        cin>>in;
        a[i]= (a[i-1] | in);
    }
    for(int i=1; i<=n; ++i){
        int in;
        cin>>in;
        b[i]=(b[i-1] | in);
    }

    int ret=0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=i; ++j){
            int aSum = a[i] & ~a[j - 1];
            int bSum= b[i] & ~b[j-1];
            ret=max(ret, aSum+bSum);
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}