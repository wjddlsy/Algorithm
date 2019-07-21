#include <iostream>
#include <vector>
#include "cstring"

using namespace std;

int cache[31];

int solve(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 0;
    if(n==2)
        return 3;
    int &ret=cache[n];
    if(ret!=-1)
        return ret;
    ret=0;
    ret=solve(n-2)*3;
    for(int i=4; i<=n; i+=2){
        ret=ret+solve(n-i)*2;
    }
    return ret;
}
int main() {
    int N;
    cin>>N;
    memset(cache, -1, sizeof(cache));
    if(N%2==1)
        cout<<0;
    else
        cout<<solve(N);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}