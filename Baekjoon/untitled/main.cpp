#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

int cache[2501][2501];
int palindrome[2501][2501];

string s;
bool isPalindrome(int l, int r) {
    deque<char> dq;
    for(int i=l; i<=r; ++i) {
        dq.push_back(s[i]);
    }
    while(dq.size()>1) {
        if(dq.back() != dq.front())
            return false;
        dq.pop_back();
        dq.pop_front();
    }
    return true;
}

int solve(int l, int r) {
    int &ret = cache[l][r];
    if(ret!=-1)
        return ret;
    ret = isPalindrome(l, r) ? 1 : 5000;
    for(int i=l; i<r; ++i) {
        ret = min(ret, solve(l, i) + solve(i+1, r) );
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, s.size()-1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}