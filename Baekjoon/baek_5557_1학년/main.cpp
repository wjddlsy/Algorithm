#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long N, number[101], cache[101][21];

long long solve(int n, int p) {
    if(p<0 || p>20)
        return 0;
    if(n==N-1 && p==number[N-1])
        return 1;
    if(n==N-1)
        return 0;
    long long &ret = cache[n][p];
    if(ret!=-1)
        return ret;
    ret = 0;
    ret = ret + solve(n+1, p + number[n]) + solve(n+1, p-number[n]);
    return ret;
}
int main() {
    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>number[i];
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(1, number[0]);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}