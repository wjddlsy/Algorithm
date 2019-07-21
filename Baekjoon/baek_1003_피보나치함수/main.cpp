#include <iostream>
#include <string.h>
using namespace std;

int cache[41][2];

int main() {
    int t;
    cin >> t;

    memset(cache, 0, sizeof(cache));
    cache[0][0]=1;
    cache[0][1]=0;
    cache[1][1]=1;
    cache[1][0]=0;

    for(int i=2; i<=40; ++i){
        cache[i][0]=cache[i-1][0]+cache[i-2][0];
        cache[i][1]=cache[i-1][1]+cache[i-2][1];
    }

    while(t--){
        int n;
        cin>>n;
        cout<<cache[n][0]<<" "<<cache[n][1]<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}