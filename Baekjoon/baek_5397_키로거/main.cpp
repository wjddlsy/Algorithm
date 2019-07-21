#include <iostream>
#include <list>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string L;
        cin>>L;

        int cur=-1, size=0;
        list<char> ret;
        auto it=ret.begin();
        for(auto &c:L){
            if(c=='<') {
                if(it==ret.begin())
                    continue;
                it--;
                cur--;
            }
            else if(c=='>') {
                if(it==ret.end())
                    continue;
                it++;
                cur++;
            }
            else if(c=='-') {
                if(it==ret.begin())
                    continue;
                it--;
                it=ret.erase(it);
            }
            else {
                it=ret.insert(it, c);
                it++;
                cur++;
            }
        }

        for(auto r:ret){
            cout<<r;
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}