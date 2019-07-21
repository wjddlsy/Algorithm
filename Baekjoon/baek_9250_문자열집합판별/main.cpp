#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ALPHABETS 26

int toNumber(char ch){ return ch-'a'; }

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<string> S;
    TrieNode* tn=new TrieNode();
    for(int i=0; i<N; ++i){
        string s;
        cin>>s;
        S.push_back(s);
        tn->insert(s.c_str(), i);
    }
    computeFailFunc(tn);
    int Q;
    cin>>Q;
    for(int i=0; i<Q; ++i){
        string q;
        cin>>q;
        vector<pair<int ,int>> tmp=ahoCorasick(q, tn);
        if(tmp.empty()){
            cout<<"NO"<<'\n';
        }
        else
            cout<<"YES"<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}