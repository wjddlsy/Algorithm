#include <iostream>
#include <vector>
using namespace std;

int main() {
    int E, S, M;
    cin>>E>>S>>M;
    int divE=15, divS=28, divM=19;

    int year=1, e=1, s=1, m=1;

    while(!(e==E && s==S && m==M)) {
        year++; e++; s++; m++;
        if(e>divE)
            e=1;
        if(s>divS)
            s=1;
        if(m>divM)
            m=1;
    }
    cout<<year;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}