# 1701 Cubeditor  

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 2398 | 693  | 500       | 33.490%   |

## 문제

Cubelover는 프로그래밍 언어 Whitespace의 코딩을 도와주는 언어인 Cubelang을 만들었다. Cubelang을 이용해 코딩을 하다보니, 점점 이 언어에 맞는 새로운 에디터가 필요하게 되었다. 오랜 시간 고생한 끝에 새로운 에디터를 만들게 되었고, 그 에디터의 이름은 Cubeditor이다.

텍스트 에디터는 찾기 기능을 지원한다. 대부분의 에디터는 찾으려고 하는 문자열이 단 한 번만 나와도 찾는다. Cubelover는 이 기능은 Cubelang에 부적합하다고 생각했다. Cubelang에서 필요한 기능은 어떤 문자열 내에서 부분 문자열이 두 번 이상 나오는 문자열을 찾는 기능이다. 이때, 두 부분 문자열은 겹쳐도 된다.

예를 들어, abcdabc에서 abc는 두 번 나오기 때문에 검색이 가능하지만, abcd는 한 번 나오기 때문에 검색이 되지를 않는다.

이렇게 어떤 문자열에서 두 번 이상 나오는 부분 문자열은 매우 많을 수도 있다. 이러한 부분 문자열 중에서 가장 길이가 긴 것을 구하는 프로그램을 작성하시오.

예를 들어, abcabcabc에서 abc는 세 번 나오기 때문에 검색할 수 있다. 또, abcabc도 두 번 나오기 때문에 검색할 수 있다. 하지만, abcabca는 한 번 나오기 때문에 검색할 수 없다. 따라서, 두 번 이상 나오는 부분 문자열 중에서 가장 긴 것은 abcabc이기 때문에, 이 문자열이 답이 된다.

## 입력

첫째 줄에 문자열이 주어진다. 문자열의 길이는 최대 5,000이고, 문자열은 모두 소문자로만 이루어져 있다.

## 출력

입력에서 주어진 문자열의 두 번이상 나오는 부분문자열 중에서 가장 긴 길이를 출력한다.

## 예제 입력 1 복사

```
abcdabcabb
```

## 예제 출력 1 복사

```
3
```



## 출처

[ACM-ICPC ](https://www.acmicpc.net/category/1)> [Regionals ](https://www.acmicpc.net/category/7)> [Asia ](https://www.acmicpc.net/category/42)> [Korea ](https://www.acmicpc.net/category/211)> [Asia Regional - Seoul 2007](https://www.acmicpc.net/category/detail/1065) B번

- 잘못된 데이터를 찾은 사람: [atomzeno](https://www.acmicpc.net/user/atomzeno)
- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 문제의 오타를 찾은 사람: [dsa2341](https://www.acmicpc.net/user/dsa2341) [klimmek55](https://www.acmicpc.net/user/klimmek55)

## 링크

- [ACM-ICPC Live Archive](https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1902)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/1701#)



# Solve

## Think

## Code

```C++
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

```

