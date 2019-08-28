#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> weights(n);
    map<int, int> w;
    for(auto &weight:weights) {
        cin>>weight;
        w[weight]++;
    }
    set<int> ret;
    sort(weights.begin(), weights.end());

    int l=1, r=n-2;

    if(weights[0]!=1)
        weights[0]--;
    weights[n-1]++;

    while(l<=r) {
        if(weights[l-1]==weights[l])
            weights[l]++;
        else if (weights[l-1]+1<weights[l])
            weights[l]--;
        if(weights[r+1]==weights[r])
            weights[r]--;
        else if (weights[r+1]-1>weights[r])
            weights[r]++;
        l++; r--;
    }
    for(int i=0; i<n; ++i) {
        ret.insert(weights[i]);
    }
    cout<<ret.size();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}