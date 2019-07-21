#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int N, M;
        cin>>N;
        vector<int> memory;
        for(int i=0; i<N; ++i) {
            int n;
            cin>>n;
            memory.push_back(n);
        }
        cin>>M;
        sort(memory.begin(), memory.end());
        for(int i=0; i<M; ++i) {
            int n;
            cin>>n;
            if(*lower_bound(memory.begin(), memory.end(), n)!=n)
                cout<<0<<'\n';
            else
                cout<<1<<'\n';
        }
    }
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}