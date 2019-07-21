#include <iostream>
#include <string.h>
using namespace std;
int chk[2];
int main() {
    int x;
    for(int k=0; k<3; ++k) {
        for (int i = 0; i < 4; ++i) {
            cin >> x;
            chk[x]++;
        }
        if(chk[0]==1)
            cout<<"A" << endl;
        else if(chk[0]==2)
            cout << "B" << endl;
        else if(chk[0]==3)
            cout << "C" << endl;
        else if(chk[0]==4)
            cout << "D" << endl;
        else
            cout << "E" << endl;
        memset(chk, 0, sizeof(chk));
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}