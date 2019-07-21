//
//  main.cpp
//  baek_4354_문자열제곱
//
//  Created by 윤정인 on 30/09/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>

using namespace std;

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

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

int main(int argc, const char * argv[]) {
    // insert code here...
    // 약수에 대해서 하기
    ios_base::sync_with_stdio(false);
    string s;
    while(s!="."){
        cin>>s;
        vector<int> pi=getPi(s);
        int n=s.size();
        int ret=n;
        for(int i=1; i<n; ++i){
            bool chk=true;
            int t=i;
            if(n%i!=0)
                continue;
            while(t<n){
                if(pi[t]==0){
                    chk=false;
                    break;
                }
                t*=i;
            }
            if(chk){
                ret=i;
                break;
            }
        }
        
        cout << n-ret+1 << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
