#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<pair<int, int>> dq(N);
    vector<int> ret;
    int top = -1;
    for(int i=0; i<N; ++i) {
        int x; cin>>x;
        auto begin = dq.begin();
        auto end = dq.begin() + top + 1;
        auto it = lower_bound(begin, end, pair<int, int>(-x, 0));
        if(it == end) {
            top ++;
            dq[top] = {-x, i};
        }
        else {
            top = distance(dq.begin(), it);
            dq[top] = {-x, i};
        }
        if(top == 0)
            ret.push_back(0);
        else
            ret.push_back(dq[top-1].second+1);
    }
    for(auto &r:ret) {
        cout<<r<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}