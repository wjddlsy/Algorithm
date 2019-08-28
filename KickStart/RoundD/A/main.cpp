#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        int N, Q;
        cin>>N>>Q;
        vector<int> arr(N);
        set<int> odd;
        for(int i=0; i<N; ++i) {
            cin>>arr[i];
            if(__builtin_popcount(arr[i])%2==1)
                odd.insert(i);
        }
        for(int i=0; i<Q; ++i) {
            int p, v;
            cin>>p>>v;
            odd.erase(p);
            if(__builtin_popcount(v)%2==1) {
                odd.insert(p);
            }
            if(odd.size()%2==0)
                cout<<N<<" ";
            else
                cout<<max(*odd.rbegin(), N-*odd.begin()-1)<<" ";
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}