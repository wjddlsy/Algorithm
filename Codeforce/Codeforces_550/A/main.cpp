#include <iostream>
#include <cstring>
using namespace std;
int cnt[26];
int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        string s;
        cin>>s;
        bool flag=true, flag2=true;
        memset(cnt, 0, sizeof(cnt));
        char last;
        for(int j=0; j<s.size(); ++j){
            char ss=s[j];
//            if(cnt[ss-'a']!=0){
//                flag=false;
//                break;
//            }
//            if(j!=0 && abs(last-ss-'a')!=1){
//                flag=false;
//                break;
//            }
            cnt[ss-'a']++;
            last=ss;
        }
        for(int j=0; j<26; ++j){
            if(cnt[j]>1){
                flag=false;
                break;
            }

            if(!flag2 && cnt[j]==1){
                flag=false;
                break;
            }

            if(cnt[j]==1){
                while(cnt[j]==1)
                    j++;
                j--;
                flag2=false;
            }
        }
        cout<<(flag?"Yes":"No")<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}