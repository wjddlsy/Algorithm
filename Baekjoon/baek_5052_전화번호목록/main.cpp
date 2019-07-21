#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int ALPHABETS = 10;
int toNumber(char ch){return ch-'0';}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    bool terminal;
    TrieNode():terminal(false){
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for(int i=0; i<ALPHABETS; ++i){
            if(children[i])
                delete children[i];
        }
    }
    bool insert(const char* key){
        if(*key==0)
            return terminal=true;
        else {
            int next=toNumber(*key);
            if(children[next]==NULL)
                children[next]=new TrieNode();
            if(children[next]->terminal)
                return false;
            return children[next]->insert(key+1);
        }
    }

    bool find(const char* key){
        if(*key==0) return true;
        int next=toNumber(*key);
        if(children[next]->terminal) return false;
        if(children[next]==NULL) return true;
        return children[next]->find(key+1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        TrieNode *tn=new TrieNode;
        vector<string> input;
        for(int i=0; i<n; ++i){
            string s;
            cin>>s;
            input.push_back(s);
            //tn->insert(s.c_str());
        }
        sort(input.begin(), input.end());
        bool flag=true;
        for(int i=0; i<n; ++i){
            flag=tn->insert(input[i].c_str());
            if(!flag)
                break;
        }
        cout<<(flag?"YES":"NO")<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}