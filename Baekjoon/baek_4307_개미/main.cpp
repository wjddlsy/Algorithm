#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int l, n;
        cin >> l >> n;
        vector<int> ants(n);
        for(auto &ant:ants) {
            cin>>ant;
        }
        int minT=0, maxT=0;
        for(auto &ant:ants) {
            minT=max(minT, min(ant, l-ant));
            maxT=max(maxT, max(ant, l-ant));
        }
        cout<<minT<<" "<<maxT<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}