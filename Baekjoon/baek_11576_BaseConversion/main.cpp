#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int A, B, m;
    cin >> A >> B >> m;
    int sum=0;
    for(int i=0; i<m; ++i) {
        int n; cin>>n;
        sum+=(int)pow(A, m-1-i)*n;
    }
    vector<int> ret;

    while(sum) {
        int digit=sum%B;
        ret.emplace_back(digit);
        sum/=B;
    }

    reverse(ret.begin(), ret.end());
    for(auto &r:ret){
        cout<<r<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}