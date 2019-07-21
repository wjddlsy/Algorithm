#include <iostream>
using namespace std;

int ret[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q, n, nPrev=0, cur=25, dir=1;
    char x;
    string command;
    cin>>Q;

    for(int i=0; i<Q; ++i){

        cin>>command>>n;

        int diff=n-nPrev;

        for(int j=0; j<26; ++j)
            ret[j]+=diff/26;

        for(int j=0; j<diff%26; ++j){
            cur=(cur+dir+26)%26;
            ret[cur]++;
        }

        if(command=="UPIT"){
            cin>>x;
            cout<<ret[x-'a']<<'\n';
        }

        else {
            dir*=-1;
        }

        nPrev=n;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}