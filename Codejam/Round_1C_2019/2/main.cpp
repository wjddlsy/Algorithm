#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int c[4]={119, 23, 5, 1};
int c2[4]={23, 5, 1, 0};
int main() {
    int T, F;
    cin>>T>>F;
    for(int t=1; t<=T; ++t){
        char n;
        string ret;
        vector<int> out;
        bool check[5]={false};

        for(int i=0; i<119; ++i){
            out.push_back(i*5+1);
        }
        for(int k=0; k<4; ++k) {
            int query=c[k];
            vector<int> cnt(6, 0);
            vector<vector<int>> pos(6);
            for (int i = 0; i < query; ++i) {
                cout << out[i] <<endl;
                cin >> n;
                cnt[n - 'A']++;
                pos[n - 'A'].push_back(out[i]);
            }
            int index = 0;
            for (int i = 0; i < 6; ++i) {
                if (cnt[i] == c2[k] && check[i]==false) {
                    index = i;
                    ret += (index + 'A');
                    check[index]=true;
                    break;
                }
            }
            out.clear();
            for(auto p:pos[index]){
                out.push_back(p+1);
            }
        }

        for(int i=0; i<5; ++i){
            if(check[i]==false) {
                ret+=(i+'A');
            }
        }
        cout<<ret<<endl;
        string verdict;
        cin>>verdict;
        assert(verdict == "Y");
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}