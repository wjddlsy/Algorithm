//
//  main.cpp
//  baek_1787_문자열의주기예측
//
//  Created by 윤정인 on 07/10/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;
    
    vector<int> pi(m, 0);
    
    for (int i = 1; i< m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]){
            pi[i] = ++j;
            if(pi[j-1]!=0)
                pi[i]=pi[j-1];
        }
    }
    return pi;
}

int ceil(int n){
    if(n%2==1)
        return n/2 + 1;
    else
        return n/2;
}
//접미사 길이 출력인거가튼대
int main(int argc, const char * argv[]) {
    // insert code here..
    int n, k;
    string s;
    cin>>n>>s;
    vector<long long> ret(n,0);
    vector<int> pi=getPi(s);
    for(int i=s.size(); i>0; --i) {
        if(pi[i-1]==0)
            ;
        else if (i - pi[i - 1] < ceil(i / 2))
            ;
        else
            ret[i - 1] = i - pi[i - 1];
    }
    //    for(int i=s.size(); i>0 ; --i){
    //        k=pi[i-1];
    //        while(k>0){
    //            if(pi[k-1]==0){
    //                if(i-k<ceil(i/2))
    //                    ;
    //                else
    //                    ret[i-1]=i-k;
    //            }
    //            k=pi[k-1];
    //        }
    //    }
    
    long long sum=0;
    for(int i=0; i<ret.size(); ++i){
        sum+=ret[i];
    }
    cout<<sum;
    //cout << accumulate(ret.begin(), ret.end(),0);
    return 0;
}


