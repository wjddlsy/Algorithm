#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;
        map<int, int> sticks;
        int maxVal=0, minVal=10000;
        for(int i=0; i<4*n; ++i) {
            int l; cin>>l;
            sticks[l]++;
            maxVal=max(l, maxVal);
            minVal=min(l, minVal);
        }
        // 젤 작은거랑 젤 큰거
        int area=minVal*maxVal;
        int l=1, r=10000;
        bool flag=true;

        for(auto st:sticks) {
            if(area%st.first!=0) {
                flag=false;
            }
            if(st.second%2!=0) {
                flag=false;
            }
            if(area%st.first!=0)
                flag=false;
            int found=area/st.first;
            auto it=sticks.lower_bound(found);
            if(it->first!=found) {
                flag=false;
            }
            if(st.second!=it->second)
                flag=false;
        }
        if(flag)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}