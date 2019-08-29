#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int A, P;
    cin>>A>>P;
    map<int, int> m;

    int index=1, ret=0;
    m[A]=index;

    while(true) {
        index++;
        int tmp=0;
        while(A) {
            tmp += (int)pow(A%10, P);
            A/=10;
        }
        A = tmp;
        if(m[A]!=0) {
            ret = m[A] - 1;
            break;
        }
        m[A]=index;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}