#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string cache[7]={"", "S", "R", "S", "P", "P", "R" };
string cache2[3]={"R", "S", "P"};

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        int A;
        bool check[500][3]={0};
        cin>>A;
        const int ALPHA=3;
        vector<vector<int>> trie;
        trie.emplace_back(ALPHA, -1);
        vector<int> visits(1, 0);
        vector<int> pv(1, -1);
        for(int i=0; i<A; ++i){
            string s;
            cin>>s;
            int tt=0; // 노드 번
            while(s.size()<=500){
                s+=s;
            }
            for(char c:string(s.begin(), s.end())){
                int d;
                if(c=='R')
                    d=0;
                else if(c=='S')
                    d=1;
                else
                    d=2;
                if(trie[tt][d]==-1){ // 노드 추가
                    trie[tt][d]=(int)trie.size();
                    trie.emplace_back(ALPHA, -1);
                    visits.push_back(0);
                    pv.push_back(tt); // 내 위에노드임
                }
                tt=trie[tt][d];
                visits[tt]++;
            }
        }
        string ret;
        int root=0;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int here=q.front();
            q.pop();
            int bit=1;
            for(int i=0; i<3; ++i){
                if(trie[here][i]!=-1){
                    bit=bit+1;
                }
                bit=bit<<1;
            }
            bit=(bit>>1)-4;
            if(bit==7){
                ret="IMPOSSIBLE";
                break;
            }
            ret+=cache[bit];
            for(int i=0; i<3; ++i){
                if(trie[here][i]==-1)
                    continue;
                if(cache[bit]=="R" && i==1){
                    continue;
                }
                if(cache[bit]=="S" && i==2)
                    continue;
                if(cache[bit]=="P" && i==0)
                    continue;
                q.push(trie[here][i]);
            }
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}