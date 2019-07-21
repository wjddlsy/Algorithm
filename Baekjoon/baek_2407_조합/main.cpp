#include <iostream>
#include <algorithm>
using namespace std;

string cache[101][101];

string bigIntegerAdd(string a, string b){
    long long sum=0;
    string ret;
    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()){
            sum+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum+=b.back()-'0';
            b.pop_back();
        }
        ret.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string solve(int n, int m){
    if(n==m || m==0)
        return "1";
    string &ret=cache[n][m];
    if(ret!="")
        return ret;
    return ret=bigIntegerAdd(solve(n-1, m-1), solve(n-1,m));

}
int main() {
    int n, m;
    cin>>n>>m;
    std::cout << solve(n, m)<<endl;
    return 0;
}