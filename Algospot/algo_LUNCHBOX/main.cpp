#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int N; cin>>N;
        vector<pair<int, int>> lunch(N);
        for(auto &l:lunch){
            cin>>l.second;
        }
        for(auto &l:lunch){
            cin>>l.first;
        }
        int ret=0, time=0;
        sort(lunch.begin(), lunch.end(), greater<pair<int, int>>());
        for(auto &l:lunch) {
            time+=l.second;
            ret=max(ret, time+l.first);
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}