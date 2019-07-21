#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        cin>>N;
        const int ALPHA=26;
        vector<vector<int>> trie;
        trie.emplace_back(ALPHA, -1);
        vector<int> visits(1, 0);
        vector<int> pv(1, -1);
        while(N--){
            string s;
            cin>>s;
            int tt=0; // 노드 번
            for(char c:string(s.rbegin(), s.rend())){
                int d=(int)(c-'A');
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
        int ans=0;
        for(int i=(int)trie.size()-1; i>=0; --i){
            if(visits[i]<2){ //
                continue;
            }
            ans++;
            int v=i;
            while(v!=-1){
                visits[v]-=2;
                v=pv[v];
            }
        }
        cout<<ans*2<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}