#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int k;
        cin>>k;
        multiset<int> ms;
        for(int i=0; i<k; ++i) {
            char command; int value;
            cin>>command>>value;
            if(command=='I') {
                ms.insert(value);
            } else {
                if(ms.empty())
                    continue;
                if(value==1) {
                    ms.erase(--ms.end());
                } else {
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty())
            cout<<"EMPTY"<<'\n';
        else
            cout<<*--ms.end()<<" "<<*ms.begin()<<" "<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}