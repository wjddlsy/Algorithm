#include <iostream>

using namespace std;

int cache[101][11];
int main() {
    int n;
    cin>>n;

    for(int i=1; i<=9; ++i){
        cache[1][i]=1;
    }

    for(int i=2; i<=n; ++i){
        for(int j=0; j<=9; ++j){
            if(j==0)
                cache[i][0]=cache[i-1][1];
            else if(j==9)
                cache[i][9]=cache[i-1][8];
            else
                cache[i][j]=(cache[i-1][j-1]+cache[i-1][j+1])%1000000000;

            cache[i][j]%=1000000000;
        }
    }

    int ret=0;
    for(int i=0; i<=9; ++i){
        ret=(ret+cache[n][i])%1000000000;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}