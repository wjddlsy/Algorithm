#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    int n; cin>>n;
    vector<int> A(n);
    for(auto& a:A){
        cin>>a;
    }
    int m; cin>>m;
    vector<int> B(m);
    for(auto& b:B){
        cin>>b;
    }
    vector<int> left, right;
    for(int i=0; i<n; ++i){
        int sum=0;
        for(int j=i; j<n; ++j){
            sum+=A[j];
            left.emplace_back(sum);
        }
    }
    for(int i=0; i<m; ++i){
        int sum=0;
        for(int j=i; j<m; ++j) {
            sum+=B[j];
            right.emplace_back(sum);
        }
    }
    sort(right.begin(), right.end());
    long long ret=0;
    for(auto &val:left){
        int target=T-val;
        auto hi=upper_bound(right.begin(), right.end(), target);
        auto lo=lower_bound(right.begin(), right.end(), target);
        ret+=hi-lo;
    }
    cout<<ret;
    //td::cout << "Hello, World!" << std::endl;
    return 0;
}