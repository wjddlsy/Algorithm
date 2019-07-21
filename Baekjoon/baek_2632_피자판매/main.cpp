#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size, m, n;
    cin>>size>>m>>n;
    vector<int> A(m), B(n);
    for(auto &a:A){
        cin>>a;
    }
    for(auto &b:B){
        cin>>b;
    }

    for(auto a:A) {
        A.emplace_back(a);
    }
    for(auto b:B){
        B.emplace_back(b);
    }
    vector<int> right, left;
    right.emplace_back(0);
    left.emplace_back(0);

    for(int i=0; i<m; ++i){
        int sum=0;
        for(int j=i; j-i<m-1; ++j) {
            sum+=A[j];
            if(sum<=size)
                left.emplace_back(sum);
        }
        if(i==0) {
            sum+=A[m-1];
            if(sum<=size)
                left.emplace_back(sum);

        }
    }
    for(int i=0; i<n; ++i){
        int sum=0;
        for(int j=i; j-i<n-1; ++j) {
            sum+=B[j];
            if(sum<=size)
                right.emplace_back(sum);
        }
        if(i==0) {
            sum+=B[n-1];
            if(sum<=size)
                right.emplace_back(sum);
        }
    }
    sort(right.begin(), right.end());
    long long ret=0;
    for(auto &val:left) {
        int target=size-val;
        auto hi=upper_bound(right.begin(), right.end(), target);
        auto lo=lower_bound(right.begin(), right.end(), target);
        ret+=hi-lo;
    }
    cout<<ret<<'\n';
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}