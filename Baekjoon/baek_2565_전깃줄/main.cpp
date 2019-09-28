#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> p;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin>>a>>b;
        p.emplace_back(a, b);
    }
    sort(p.begin(), p.end());
    vector<int> lis {-INF, };

    for(auto &pp:p) {
        if(lis.back() < pp.second)
            lis.emplace_back(pp.second);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), pp.second);
            *it = pp.second;
        }
    }
    cout<<n-lis.size()+1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}