#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;

    vector<int> pi(m, 0);

    for (int i = 1; i< m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}


vector<int> kmp(string s, string p)
{
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j>0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ans;
}

int main() {
    int n, in;
    cin>>n;
    string a,b;

    for(int i=0; i<360000; ++i){
        a+='0';
        b+='0';
    }
    for(int i=0; i<n; ++i){
        cin >> in;
        a[in]='1';
    }
    for(int i=0; i<n; ++i){
        cin>>in;
        b[in]='1';
    }
    a=a+a;
    vector<int> ret=kmp(a, b);
    if(ret.empty())
        cout<<"impossible";
    else
        cout<<"possible";
    return 0;
}