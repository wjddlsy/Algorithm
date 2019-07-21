#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int ALPHABETS=26;
int toNumber(char chr){
    return chr-'A';
}

vector<string> board;
set<string> ret;
bool visited[4][4];
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,-1,0,1,-1,0,1 };

int scoreboard[]={0,0,0,1,1,2,3,5,11};

bool isRange(int x, int y){
    if(x<0 || y<0 || x>=4 || y>=4) return false;
    return true;
}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    bool terminal;
    TrieNode():terminal(false){
        memset(children, 0, sizeof(children));
    }
    ~TrieNode(){
        for(int i=0; i<ALPHABETS; ++i){
            if(children[i])
                delete(children[i]);
        }
    }
    void insert(const char* key){
        if(*key==0)
            terminal=true;
        else {
            int next=toNumber(*key);
            if(children[next]==NULL)
                children[next]=new TrieNode();
            children[next]->insert(key+1);
        }
    }
    TrieNode* find(const char* key){
        if(*key==0) return this;
        int next=toNumber(*key);
        if(children[next]==NULL) return NULL;
        return children[next]->find(key+1);
    }
    void solve(int x, int y, string s){
        if(!isRange(x, y))
            return;
        if(visited[y][x])
            return;
        if(s.size()>=8)
            return;
        visited[y][x]=true;
        s=s+board[y][x];
        if(children[toNumber(board[y][x])]==NULL){
            visited[y][x]=false;
            return;
        }
        if(children[toNumber(board[y][x])]->terminal)
            ret.insert(s);
        for(int i=0; i<8; ++i){
             children[toNumber(board[y][x])]->solve(x+dx[i], y+dy[i], s);
        }
        visited[y][x]=false;

    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin>>w;
    TrieNode *tn=new TrieNode;
    for(int i=0; i<w; ++i){
        string s;
        cin>>s;
        tn->insert(s.c_str());
    }

    int b;
    cin>>b;
    for(int i=0; i<b; ++i){
        board.clear();
        ret.clear();
        for(int j=0; j<4; ++j){
            string s;
            cin>>s;
            board.push_back(s);
        }
        for(int y=0; y<4; ++y){
            for(int x=0; x<4; ++x)
                tn->solve(y, x, "");
        }
        int sum=0;
        string longest="";
        for(auto r:ret){
            if(r.size()>longest.size())
                longest=r;
            sum+=scoreboard[r.size()];
        }
        cout<<sum<<" "<<longest<<" "<<ret.size()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
