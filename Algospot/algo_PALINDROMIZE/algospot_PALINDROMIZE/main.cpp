//
//  main.cpp
//  algospot_PALINDROMIZE
//
//  Created by 윤정인 on 2018. 9. 27..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int C;


//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용하여 계산
vector<int> getPartialMatch(const string& N){
    int m=N.size();
    vector<int> pi(m,0);
    //KMP로 자기자신을 찾는다
    //N을 N에서 찾는다. begin=0 이면 자기자신을 찾아버리니까 안됨
    int begin=1, matched=0;
    // 비교할 문자가 N의 끝에 도달할때까지 찾으면서 부분 일치를 모두 기록
    while(begin+matched<m){
        if(N[begin+matched]==N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched==0)
                matched++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int maxOverlap(const string &a, const string &b){
    int n=a.size(), m=b.size();
    vector<int> pi=getPartialMatch(b);
    
    int begin=0, matched=0;
    while(begin<n){
        if(matched<m && a[begin+matched]==b[matched]){
            matched++;
            if(begin+matched==n)
                return matched;
        }
        else{
            if(matched==0)
                ++begin;
            else{
                begin+=matched-pi[matched-1];
                matched=pi[matched-1];
            }
        }
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    cin >> C;
    while(C--){
        cin >> s;
        string b=s;
        reverse(b.begin(), b.end());
        cout << 2*s.size()-maxOverlap(s, b) << endl;
    }
    //std::cout << "Hello, World!\n";
    
    return 0;
}
