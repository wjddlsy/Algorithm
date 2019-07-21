#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

int GCD(int u, int v) {
    while ( v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin>>n;
    string tmp, s, answer;
    getline(cin, tmp);
    getline(cin, s);
    getline(cin, answer);
    string ss=s+" "+s;
    ss.erase(ss.begin());
    vector<int> ret=kmp(ss, answer);

    int d=GCD(ret.size(), n);
    cout << ret.size()/d << "/" << n/d;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}