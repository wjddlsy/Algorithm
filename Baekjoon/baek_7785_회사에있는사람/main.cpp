#include <iostream>
#include <map>
#include <functional>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<string, bool, greater<string>> m;
    while(n--){
        string name, state;
        cin>>name>>state;
        if(state=="enter"){
            auto ret=m.insert({name, true});
            if(ret.second==false){
                m[name]=true;
            }
        }
        else {
            m[name]=false;
        }
    }
    for(auto mm:m){
        if(mm.second)
            cout<<mm.first<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}