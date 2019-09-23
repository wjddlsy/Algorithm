#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000005;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}
int main() {
    int N;
    cin>>N;
    vector<pair<int, int>> lis{{-INF, 0}};
    vector<int> parent(N+1);
    vector<int> arr(N+1);
    for(int i=1; i<=N; ++i) {
        int x; cin>>x;
        arr[i] = x;
        if(lis.back().first<x) {
            lis.emplace_back(x, i);
            parent[i] = lis[lis.size()-2].second;
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), make_pair(x, 0), comp);
            *it = {x, i};
            parent[i] = (it-1)->second;
        }
    }
    int start = lis.back().second;

    vector<int> ret;
    while(start!=0) {
        ret.emplace_back(arr[start]);
        start = parent[start];
    }
    reverse(ret.begin(), ret.end());
    cout << lis.size()-1 << '\n';
    for(auto &s:ret) {
        cout << s << " ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}