# 돌연변이 성공한국어   

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 256 MB      | 1645 | 315  | 157       | 17.800%   |

## 문제

인간의 DNA 구조는 A, C, G, T로 이루어진 하나의 긴 문자열로 표현할 수 있다.

이때, 몇 몇 질병은 DNA 구조를 나타낸 문자열의 어떤 연속된 부분 문자열과 관련이 있다는 것이 밝혀져 있다. 만일 DNA가 특정 문자열을 부분 문자열로 가진다면 그 질병에 걸릴 가능성이 높다는 것이다. 이러한 특정 문자열을 마커(marker)라 한다.

하지만 때때로 DNA 구조를 그대로 확인하는 것만으로는 질병과 관련된 마커를 확인할 수 없는 경우가 있다. 마커의 돌연변이 가능성 때문이다.

마커의 돌연변이는 아래와 같이 일어난다.

- 먼저, 마커를 세 부분으로 나눈다, 이때, 첫 부분과 세 번째 부분은 비어 있어도 된다.
- 두 번째 부분을 뒤집는다.

예를 들어 마커가 AGGT라면 아래와 같은 여섯 가지 경우가 가능하다.

GAGT, GGAT, TGGA, AGGT, ATGG, AGTG

어떤 사람의 DNA 구조와 마커가 주어졌을 때, DNA 내에 마커가 돌연변이의 형태를 포함하여 몇 번 출현하는지 세는 프로그램을 작성하라.

단, 마커의 출현 위치는 서로 겹쳐도 된다. 예를 들어 DNA 구조가 ATGGAT이며 마커가 AGGT라면 답은 3이 된다. ATGG, TGGA, GGAT가 한 번씩 출현하기 때문이다.

## 입력

첫 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 줄엔 두 개의 정수 n과 m이 주어진다. 이는 각각 DNA 문자열의 길이와 마커의 길이이다. (1 ≤ n ≤ 1,000,000, 1 ≤ m ≤ 100) 두 번째 줄엔 DNA 구조가 주어진다. 마지막 줄엔 마커가 주어진다.

모든 DNA와 마커는 A,G,T,C로만 이루어진 문자열이다.

## 출력

각 테스트 케이스마다 주어진 DNA 구조에 마커와 그 돌연변이가 몇 번 출현하는지 하나의 정수로 출력한다.

만일 DNA 구조 내에 마커 또는 그 돌연변이가 한 번도 출현하지 않는다면 답은 0이 된다.

## 예제 입력 1 복사

```
2
6 4
ATGGAT
AGGT
6 4
ATGGAT
AGCT
```

## 예제 출력 1 복사

```
3
0
```



## 출처

[ACM-ICPC ](https://www.acmicpc.net/category/1)> [Regionals ](https://www.acmicpc.net/category/7)> [Asia ](https://www.acmicpc.net/category/42)> [Korea ](https://www.acmicpc.net/category/211)> [Nationwide Internet Competition ](https://www.acmicpc.net/category/256)> [Daejeon Nationalwide Internet Competition 2014](https://www.acmicpc.net/category/detail/1283) G번

- 데이터를 만든 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 문제를 번역한 사람: [portableangel](https://www.acmicpc.net/user/portableangel)

## 알고리즘 분류

- [아호코라식](https://www.acmicpc.net/problem/tag/%EC%95%84%ED%98%B8%EC%BD%94%EB%9D%BC%EC%8B%9D)



## Solve

### IDEA

#### REVERSE 

`void reverse(BidirectionalIterator fisrt, BidirectionalIterator last)`

- first ~ last 범위를 뒤집어 주는 효과 

  ```c++
  // reverse algorithm example
  int main () {
      string s="12345678";
      reverse(s.begin()+2, s.begin()+4);
      cout<<s; // results: 12435678
  }
  ```

  

### Code

```c++
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ALPHABETS 4
int toNumber(char ch){
    if(ch=='A')
        return 0;
    if(ch=='C')
        return 1;
    if(ch=='G')
        return 2;
    if(ch=='T')
        return 3;
}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    TrieNode* fail;
    vector<int> output;

    TrieNode():terminal(-1), fail(NULL){
        fill(children, children+ALPHABETS, nullptr);
    }
    ~TrieNode(){
        for(int i=0; i<ALPHABETS; ++i){
            if(children[i])
                delete children[i];
        }
    }

    void insert(const char* key, int id){
        if(*key==0){
            terminal=id;
            return;
        }
        int next=toNumber(*key);
        if(children[next]==NULL)
            children[next]=new TrieNode();
        children[next]->insert(key+1, id);
    }

    TrieNode* find(const char* key){
        if(*key==0) return this;
        int next=toNumber(*key);
        if(children[next]==NULL) return NULL;
        return children[next]->find(key+1);
    }
};

void computeFailFunc(TrieNode* root){
    queue<TrieNode*> q;
    root->fail=root;
    q.push(root);
    while(!q.empty()){
        TrieNode* here=q.front();
        q.pop();
        for(int edge=0; edge<ALPHABETS; ++edge){
            TrieNode* child=here->children[edge];
            if(!child) continue;
            if(here==root)
                child->fail=root;
            else {
                TrieNode* t=here->fail;
                while(t!=root && t->children[edge]==NULL)
                    t=t->fail;
                if(t->children[edge]) t=t->children[edge];
                child->fail=t;
            }
            child->output=child->fail->output;
            if(child->terminal!=-1)
                child->output.push_back(child->terminal);
            q.push(child);
        }
    }
}

vector<pair<int, int>> ahoCorasick(const string& s, TrieNode* root){
    vector<pair<int, int>> ret;
    TrieNode* state=root;
    for(int i=0; i<s.size(); ++i) {
        int chr=toNumber(s[i]);
        while(state!=root && state->children[chr]==NULL)
            state=state->fail;
        if(state->children[chr]) state=state->children[chr];
        int j=0;
        for(j=0; j<state->output.size(); ++j) {
            ret.push_back({i, state->output[j]});
        }
    }
    return ret;
}

TrieNode* makeMutant(string& s){
    TrieNode* tn=new TrieNode();
    int id=0;
    for(int i=0; i<s.size(); ++i){
        string tmp="";
        for(int j=i+1; j<=s.size(); ++j){
            reverse(s.begin()+i, s.begin()+j);
            tn->insert(s.c_str(), id);
            reverse(s.begin()+i, s.begin()+j);
            id++;
        }
    }
    return tn;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n, m;
        string dna,marker;
        cin>>n>>m;
        cin>>dna>>marker;
        TrieNode* mutants=makeMutant(marker);
        computeFailFunc(mutants);
        vector<pair<int, int>> ret=ahoCorasick(dna, mutants);
        cout<<ret.size()<<'\n';
        delete mutants;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

