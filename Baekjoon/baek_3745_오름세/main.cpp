#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    while(cin>>N) {
        vector<int> lis{-987654321};
        for(int i=0; i<N; ++i) {
            int x; cin>>x;
            if(lis.back() < x) {
                lis.emplace_back(x);
            } else {
                auto it = lower_bound(lis.begin(), lis.end(), x);
                *it = x;
            }
        }

        cout << lis.size() -1 << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}