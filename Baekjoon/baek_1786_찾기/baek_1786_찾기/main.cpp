//
//  main.cpp
//  baek_1786_찾기
//
//  Created by 윤정인 on 30/09/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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

vector<int> kmpSearch(const string& H, const string& N){
    int n=H.size(), m=N.size(); //문자열 길이
    vector<int> ret;
    //pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
    vector<int> pi=getPartialMatch(N);
    int begin=0, matched=0;
    while(begin <= n-m){
        // 만약 N의 해당 글자가 H의 해당 글자와 같다면
        if(matched<m && H[begin+matched]==N[matched]){
            ++matched;
            //결과적으로 m글자가 모두 일치했다면 답에 추가
            if(matched==m) ret.push_back(begin);
        } // 어디까지 일치했는지 찾게 됨
        else{
            // 일치하는 글자가 하나도 없는 경우는 다음 칸부터 계속
            if(matched==0)
                ++begin;
            else{
                begin +=matched - pi[matched-1]; // 시작 위치 잡기
                //begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
                //옮긴 후에도 pi[matched-1] 만큼은 항상 일치하기 때문.
                matched=pi[matched-1];
            }
        }
    } // 더이상 비교할 것이 없을때까지
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> result=kmpSearch(T, P);
    cout << result.size() << endl;
    for(auto &s:result){
        cout << s+1 << " ";
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}


