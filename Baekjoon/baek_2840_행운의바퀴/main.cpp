#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin>>N>>K;
    vector<bool> chk(26, false);
    vector<char> ret(N, '?');
    int index=0, start=0;
    for(int i=0; i<K; ++i){
        int s;
        char c;
        cin>>s>>c;
        index=(index+s)%N;
        if(ret[index]!='?' && ret[index]!=c){
            cout<<'!';
            return 0;
        }
        ret[index]=c;
        if(i==K-1)
            start=index;
    }

    for(auto &c:ret){
        if(c=='?')
            continue;
        if(!chk[c])
            chk[c]=true;
        else {
            cout<<'!';
            return 0;
        }
    }
    int cnt=N;
    while(cnt--){
        cout<<ret[start];
        start--;
        if(start==-1)
            start=N-1;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}