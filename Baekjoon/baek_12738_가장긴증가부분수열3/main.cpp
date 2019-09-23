#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin>>N;
    vector<long long> lis{-1000000005};
    for(int i=0; i<N; ++i) {
        long long x; cin>>x;
        if(lis.back() < x)
            lis.emplace_back(x);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }
    cout << lis.size() - 1 ;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}