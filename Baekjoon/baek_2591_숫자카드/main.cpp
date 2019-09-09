#include <iostream>
#include <cstring>

using namespace std;

int cache[41];
string s;
int solve(int n) {
    if(n<0)
        return 1;
    int &ret = cache[n];
    if(ret!=-1)
        return ret;
    ret = 0;
    if(s[n]>'0')
        ret += solve(n-1);
    if(n!=0 && s[n-1]>'0' && ( s[n-1] <'3' ||  ( s[n-1]=='3' &&  s[n] <='4') ))
        ret += solve(n-2);

    return ret;
}
int main() {
    cin >> s;
    memset(cache, -1, sizeof(cache));
    cout<<solve(s.size()-1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}