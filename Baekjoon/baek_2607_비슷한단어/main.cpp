#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    int m[101][26]={};
    for(int i=0; i<n; ++i) {
        string s; cin>>s;
        for(auto c:s) {
            m[i][c-'A']++;
        }
    }
    int ret=0;
    for(int i=1; i<n; ++i) {
        bool flag = true;
        bool plus = false, minus=false;
        for(int j=0; j<26; ++j) {
            if(abs(m[0][j]-m[i][j])>1) {
                flag=false;
                break;
            } else if (m[0][j]-m[i][j]==1) {
                if(minus) {
                    flag = false;
                    break;
                }
                minus = true;
            } else if (m[0][j]-m[i][j]==-1) {
                if(plus) {
                    flag=false;
                    break;
                }
                plus=true;
            }
        }
        if(flag)
            ret++;
    }
    cout<<ret;
    return 0;
}