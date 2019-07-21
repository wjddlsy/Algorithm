#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// 알파벳 대문자를 저장하는 경우 각 노드는 26개의 자손을 가질 수 있다.
const int ALPHABETS = 26;
int toNumber(char ch) {return ch-'a';}
// 트라이의 한 노드를 나타내는 객체
struct TrieNode {
    TrieNode* children[ALPHABETS];
    int nChild;
    bool terminal;
    bool isRoot;
    TrieNode(bool root):terminal(false), nChild(0), isRoot(root){
        memset(children, 0, sizeof(children));
    }
    ~TrieNode(){
        for(int i=0; i<ALPHABETS; ++i){
            if(children[i])
                delete children[i];
        }
    }
    void insert(const char* key){
        //문자열이 끝나면 terminal만 참으로 바꾸고 종료
        if(*key==0)
            terminal=true;
        else {
            int next=toNumber(*key);
            // 해당 자식 노드가 없다면 생성한다.
            if(children[next]==NULL) {
                children[next] = new TrieNode(false);
                nChild++;
            }
            // 해당 자식 노드로 재귀 호출
            children[next]->insert(key+1);
        }
    }
    // 이 노드를 루트로 하는 트라이에 문자열 key와 대응되는 노드를 찾는다.
    // 없으면 NULL을 반환
    TrieNode* find(const char* key, int& n){
        if(*key==0) return this;
        int next=toNumber(*key);
        if(children[next]==NULL) return NULL;
        if( (this->terminal || this->nChild>1) || this->isRoot)
            n++;
        return children[next]->find(key+1, n);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    while(cin>>t){
        TrieNode *tn=new TrieNode(true);
        vector<string> strings;
        for(int i=0; i<t; ++i){
            string s;
            cin>>s;
            strings.push_back(s);
            tn->insert(s.c_str());
        }
        double sum=0;
        for(auto s:strings){
            int n=0;
            tn->find(s.c_str(), n);
            sum+=n;
        }
        cout<<fixed;
        cout.precision(2);
        cout<<sum/t<<'\n';
        delete tn;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}