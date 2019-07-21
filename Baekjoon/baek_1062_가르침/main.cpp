#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ret=0;
vector<int> words;
void pick(int status, int smallest) {
    if( __builtin_popcount(status)==K ){
        int sum=0;
        for(auto &word:words){
            sum+=( (word & ~status) == 0);
        }
        ret=max(ret, sum);
        return;
    }
    for(int p=smallest+1; p<26; ++p) {
        status |= (1<<p);
        pick(status, p);
        status &= ~(1<<p);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    words=vector<int>(N, 0);
    for(int i=0; i<N; ++i){
        string s;
        cin>>s;
        for(auto &c:s) {
            int index=c-'a';
            words[i]|=(1<<index);
        }
    }
    pick(0, -1);
    cout<<ret;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}