#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int cache[500];

int lis(const vector<int>& s, int start){
    int& ret=cache[start];
    if(ret!=-1) return ret;

    ret=1;
    for(int next=start+1; next<s.size(); ++next){
        if(s[start]<s[next])
            ret=max(ret, lis(s, next)+1);
    }
    return ret;
}

int main() {
    int c;
    cin>>c;
    while(c--){
        vector<int> s;
        int max=0;
        memset(cache, -1, sizeof(cache));
        int n, in;
        cin>>n;
        for(int i=0; i<n; ++i){
            cin>>in;
            s.push_back(in);
        }

        for(int start=0; start<s.size(); ++start) {
            max=std::max(max, lis(s, start));
        }

        cout << max<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}