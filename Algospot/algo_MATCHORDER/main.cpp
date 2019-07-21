#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int C;
    cin>>C;
    while(C--){
        int N;
        cin>>N;
        vector<int> russia(N);
        multiset<int> korea;
        for(auto &stat:russia){
            cin>>stat;
        }
        for(int i=0; i<N; ++i) {
            int stat;
            cin >> stat;
            korea.insert(stat);
        }
        int ret=0;
        for(auto &stat:russia){
            auto it=korea.lower_bound(stat);
            if(it==korea.end()){
                korea.erase(korea.begin());
            }
            else {
                korea.erase(it);
                ++ret;
            }
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}