#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n; cin>>n;
    vector<int> A(n), B(n), C(n), D(n);
    for(int i=0; i<n; ++i){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    vector<int> right, left;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            left.emplace_back(A[i]+B[j]);
            right.emplace_back(C[i]+D[j]);
        }
    }
    sort(right.begin(), right.end());
    long long ret=0;

    for(auto &val:left) {
        long long target=-val;
        auto hi=upper_bound(right.begin(), right.end(), target);
        auto lo=lower_bound(right.begin(), right.end(), target);

        long long num=hi-lo;
        ret+=num;
    }

    cout<<ret;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}