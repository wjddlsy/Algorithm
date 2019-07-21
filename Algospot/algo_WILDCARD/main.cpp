#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int cache[101][101];

//bruteforce
bool match(const string& w, const string& s){
    int pos = 0;

    while(pos<s.size() && pos<w.size()){
        if(w[pos]=='?' || w[pos]==s[pos])
            ++pos;
    }
    // 더 이상 대응할 수 없으면 왜 whlie문이 끝나는지 확인
    if(pos==w.size())
        return pos==s.size();
    // *을 만나서 끝난 경우........................
    if(w[pos]=='*'){
        for(int skip=0; pos+skip<=s.size(); ++skip){
            if(match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
        }
    }
    return false;

}

// dp
// dp에 도대체 멀ㅇ넣ㅇ므 ?
int matchMemoized(const string& w, const string& s, int w_pos, int s_pos){
    int& ret=cache[w_pos][s_pos];
    if(ret!=-1)
        return ret;
    //1. 대응하는 경우
    while(w_pos<w.size() && s_pos<s.size() && (w[w_pos]=='?' || w[w_pos]==s[s_pos])){
        w_pos++;
        s_pos++;
    }

    if(w_pos==w.size()){
        ret = (s_pos==s.size());
        return ret;
    }

    if(w[w_pos]=='*'){
        for(int skip=0; s_pos+skip<=s.size(); ++skip){
            if(matchMemoized(w, s, w_pos+1, s_pos+skip)) {
                ret = 1;
                return ret;
            }
        }
    }
    ret=0;
    return ret;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        //memset(cache, -1, sizeof(cache));
        set<string> a;
        string w, s;
        int n;
        cin>>w>>n;
        for(int i=0; i<n; ++i){
            cin>>s;
            memset(cache,-1, sizeof(cache));
            if(matchMemoized(w, s, 0, 0))
                a.insert(s);
        }
        for(auto aa:a)
            cout << aa << endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}