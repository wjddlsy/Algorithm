#include <iostream>

using namespace std;
int main() {
    int n;
    string s;
    cin>>n>>s;

    string ret;
    int cnt=0;
    char mostbit=ret[n-1];

    char overflow='1';
    for(int i=0; i<n; ++i){
        if(s[i]=='1' && overflow=='1'){
            ret+='0';
        }
        else if(s[i]=='1' && overflow=='0'){
            ret+='1';
        }
        else if(s[i]=='0' && overflow=='1'){
            ret+='1';
            overflow='0';
        }
        else if(s[i]=='0' && overflow=='0'){
            ret+='0';
        }
    }

    for(int i=0; i<n; ++i){
        if(s[i]!=ret[i])
            cnt++;
    }
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}