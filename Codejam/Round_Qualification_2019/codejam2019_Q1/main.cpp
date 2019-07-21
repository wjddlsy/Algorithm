#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string N;

pair<string, string> solve(){
    string B;
    bool flag=false;
    for(int i=0; i<N.size(); ++i){
        if(N[i]=='4'){
            N[i]='3';
            B.push_back('1');
            flag=true;
        }
        else if(flag)
            B.push_back('0');
    }

    return {N, B};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>N;
        pair<string, string> ret=solve();
        cout<<"Case #"<<t<<": "<<ret.first
        <<" "<<ret.second<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}