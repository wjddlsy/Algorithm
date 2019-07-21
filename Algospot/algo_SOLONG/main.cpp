#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;

#define ALPHABETS 26

int toNumber(char key){
    return key-'A';
}
struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    int first; // 이 노드를 루트로 하는 트라이에 가장 먼저 추가된 단어의 번호, -1로 초기화
    TrieNode():terminal(-1), first(-1){
        memset(children, 0, sizeof(children));
    }
    ~TrieNode(){
        for(int i=0; i<ALPHABETS; ++i){
            if(children[i])
                delete children[i];
        }
    }
    void insert(const char* key, int id){
        if(first==-1) first=id;
        if(*key==0)
            terminal=id;
        else {
            int next=toNumber(*key);
            if(children[next]==NULL)
                children[next]=new TrieNode();
            children[next]->insert(key+1, id);
        }
    }
    // 이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다.
    // 없으면 NULL을 반환
    TrieNode* find(const char* key){
        if(*key==0) return this;
        int next=toNumber(*key);
        if(children[next]==NULL) return NULL;
        return children[next]->find(key+1);
    }

    int type(const char*key, int id){
        if(*key==0) return 0;
        if(first==id) return 1;
        int next=toNumber(*key);
        return 1+children[next]->type(key+1, id);
    }
};

int countKeys(TrieNode* trie, const char* word){
    TrieNode* node=trie->find(word);
    if(node==NULL || node->terminal==-1) return strlen(word);
    return trie->type(word, node->terminal);

}

TrieNode* readInput(int words){
    vector<pair<int, string>> input;
    for(int i=0; i<words; ++i){
        string buf;
        int freq;
        cin>>buf>>freq;
        input.push_back({-freq, buf});
    }
    sort(input.begin(), input.end());
    TrieNode* trie=new TrieNode();
    for(int i=0; i<input.size(); ++i){
        trie->insert(input[i].second.c_str(), i);
    }
    trie->first=-1;
    return trie;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin>>C;
    while(C--){
        int N, M;
        cin>>N>>M;
        TrieNode* trie=readInput(N);
        int ret=M-1;
        for(int i=0; i<M; ++i){
            char s[11];
            cin>>s;
            ret+=countKeys(trie, s);
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}