#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;

        int prev=0;
        cin>>prev;
        prev--;
        bool clock=true, anti=true;
        for(int i=1; i<n; ++i) {
            int cur; cin>>cur;
            cur--;
            if((prev+1)%n!=cur)
                clock=false;
            if((prev+n-1)%n!=cur)
                anti=false;
            prev=cur;
        }
        if(clock || anti)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}