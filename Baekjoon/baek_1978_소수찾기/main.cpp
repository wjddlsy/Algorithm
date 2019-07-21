#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, input, cnt=0;
    cin>>n;
    while(n--){
        cin>>input;
        bool chk=true;
        if(input==1)
            continue;
        if(input==2)
        {
            cnt++;
            continue;
        }
        for(int i=2; i<=sqrt(input)+1; ++i){
            if(input%i==0) {
                chk=false;
                break;
            }
        }
        if(chk)
            cnt++;
    }
    cout << cnt;
    return 0;
}