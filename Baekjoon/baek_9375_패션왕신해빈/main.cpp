#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){

        map<string, int> m;
        int n, type_n=0;
        cin>>n;
        while(n--){
            string name, type;
            cin>>name>>type;
            auto ret=m.insert({type, 1});
            if(ret.second==false){
                ret.first->second++;
            }
        }

        int ret=1;
        for(auto mm:m){
            ret*=(mm.second+1);
        }

        cout<<ret-1<<'\n';
        //cout<<solve(v)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}