#include <iostream>
using namespace std;

int N;
string P;

string solve(){
    pair<int, int> cur={0, 0};
    string ret;
    for(int i=0; i<P.size(); ++i){
        if(P[i]=='S'){
            ret.push_back('E');
        }
        else {
            ret.push_back('S');
        }
    }
    return ret;
}
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>N>>P;
        // S; south E; east
        cout<<"Case #"<<t<<": "<<solve()<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}