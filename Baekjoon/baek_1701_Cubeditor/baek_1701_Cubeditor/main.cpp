//
//  main.cpp
//  baek_1701_Cubeditor
//
//  Created by 윤정인 on 30/09/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Comparator{
    vector<int>& group;
    int t;
    Comparator(vector<int>& _group, int _t):group(_group), t(_t){
        t=_t;
        group=_group;
    }
    
    bool operator()(int a, int b){
        if(group[a]!=group[b]) return group[a]<group[b];
        return group[a+t]<group[b+t];
    }
};

vector<int> getSuffixArray(const string& s){
    int n=s.size();
    int t=1;
    vector<int> group(n+1);
    for(int i=0; i<n; ++i) group[i]=s[i];
    group[n]=-1;
    vector<int> perm(n);
    for(int i=0; i<n; ++i) perm[i]=i;
    while(t<n){
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t*=2;
        if(t>=n) break;
        vector<int> newGroup(n+1);
        newGroup[n]=-1;
        newGroup[perm[0]]=0;
        for(int i=1; i<n; ++i){
            if(compareUsing2T(perm[i-1],perm[i]))
                newGroup[perm[i]]=newGroup[perm[i-1]]+1;
            else
                newGroup[perm[i]]=newGroup[perm[i-1]];
            
        }
        group=newGroup;
    }
    return perm;
}
//s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int i, int j){
    int k=0;
    while(i<s.size() && s.size() && s[i]==s[j]){
        ++i;++j;++k;
    }
    return k;
}

//s의 서로 다른 부분 문자열의 수를 센다.
int countSubsring(const string& s){
    int n=s.size();
    vector<int> a=getSuffixArray(s);
    int ret=0;
    int max=0;
    for(int i=0; i<a.size(); ++i){
        int cp=0;
        if(i>0) cp=commonPrefix(s, a[i-1], a[i]);
        max=std::max(max, cp);
    }
    
    return max>2?max:0;
    
//    map<string, int> m;
//    for(auto index:a){
//        for(int i=0; i<=n-index; ++i){
//            m[s.substr(index, i)]++;
//        }
//    }
//
//    return m;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    cin >> s;
    cout << countSubsring(s);
//    map<string,int> m=countSubsring(s);
//    int max=0;
//    for(auto mm:m){
//        if(mm.second>=2){
//            if(mm.first.size()>max)
//                max=mm.first.size();
//        }
//    }
    //std::cout << max;
    return 0;
}
