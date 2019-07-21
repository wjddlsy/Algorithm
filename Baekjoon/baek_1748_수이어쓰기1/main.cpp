#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    int ret=0;
    for(int i=1; i<=n; ++i){
        if(i<10)
            ret++;
        else if (i<100)
            ret+=2;
        else if (i<1000)
            ret+=3;
        else if (i<10000)
            ret+=4;
        else if (i<100000)
            ret+=5;
        else if(i<1000000)
            ret+=6;
        else if(i<10000000)
            ret+=7;
        else if(i<100000000)
            ret+=8;
        else
            ret+=9;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}