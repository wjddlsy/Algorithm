#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define ALPHABETS 26

int toNumber(char ch){ return ch-'a'; }

struct TrieNode {
    TrieNode* children[ALPHABETS];
    TrieNode* next[ALPHABETS];
    int terminal, no; // 현 위치에서 끝나는 문자열 번호
    TrieNode* fail;
    vector<int> output;

    TrieNode():terminal(-1), fail(NULL), no(-1){
        fill(children, children+ALPHABETS, nullptr);
        fill(next, next+ALPHABETS, nullptr);
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
    for(int i=0; i<s.size(); ++i){
        int chr=toNumber(s[i]);
        while(state!=root && state->children[chr]==NULL)
            state=state->fail;
        if(state->children[chr]) state=state->children[chr];
        for(int j=0; j<state->output.size(); ++j)
            ret.push_back({i, state->output[j]});
    }
}

const int MOD=10007;
int cache[101][1001];
// 앞으로 length 글자를 더 만들어야 하는데, 아호-코라식 알고리즘의
//현재 상태가 state에 주어 질 때 IDS에 걸리지 않는 문자열의 수는 ?
int count(int length, TrieNode* state){
    if(state->output.size()) return 0;
    // 기저사례: 문자열을 전부 만든 경우
    if(length==0) return 1;
    int& ret=cache[length][state->no];
    if(ret!=-1) return ret;
    ret=0;
    // 다음으로 letter글자를 넣을 경우
    for(int letter=0; letter<ALPHABETS; ++letter){
        ret+=count(length-1, state->next[letter]);
        ret%=MOD;
    }
    return ret;
}

void computeTransition(TrieNode* here, int& nodeCounter){
    here->no = nodeCounter++;
    // here뒤에 글자 chr을 붙였을 때 어느 상태로 가ㅡㄴ가
    for(int chr=0; chr<ALPHABETS; ++chr){
        // next[] 값을 계산해 저장
        TrieNode* next=here;
        while(next!= next->fail && next->children[chr]==NULL)
            next=next->fail;
        if(next->children[chr]) next=next->children[chr];
        here->next[chr]=next;
        // 재귀적으로 무든 노드에 대해 전이 테이블 ㅖ산
        if(here->children[chr])
            computeTransition(here->children[chr], nodeCounter);
    }
}
int main() {
    int C;
    cin>>C;
    while(C--){
        int N, M;
        cin>>N>>M;
        TrieNode tn;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<M; ++i){
            char s[11];
            cin>>s;
            tn.insert(s, i);
        }
        computeFailFunc(&tn);
        int nodeCounter=0;
        computeTransition(&tn, nodeCounter);
        cout<<count(N, &tn)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}