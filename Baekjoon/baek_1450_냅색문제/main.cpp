#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, weights[30];
void solve(int here, int remain, int end, vector<int>& bag) {
    if(remain<0)
        return;
    if(here == end) {
        bag.emplace_back(C-remain);
        return;
    }
    solve(here+1, remain, end, bag);
    solve(here+1, remain-weights[here], end, bag);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>C;
    for(int i=0; i<N; ++i) {
        cin>>weights[i];
    }
    vector<int> bag1, bag2;
    solve(0, C, N/2, bag1);
    solve(N/2, C, N, bag2);

    sort(bag2.begin(), bag2.end());
    long long ret = 0;
    for(auto &w:bag1) {
        auto it = upper_bound(bag2.begin(), bag2.end(), C-w);
        ret += distance(bag2.begin(), it);
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}