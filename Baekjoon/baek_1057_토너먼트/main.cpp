#include <iostream>

using namespace std;

int main() {
    int n, kim, im,round=0;
    cin >> n >> kim >> im;
    // 만났다는 것의 의미
    while(kim!=0 && im!=0){
        if(kim==im) {
            cout << round;
            return 0;
        }
        if(kim%2==1){
            kim=(kim+1)/2;
        }
        else {
            kim=kim/2;
        }

        if(im%2==1){
            im=(im+1)/2;
        }
        else
            im=im/2;
        round++;
    }
    cout << -1;
    return 0;
}