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