#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin>>N>>L;

    deque<pair<int, int>> dq;

    int size=0;
    dq.push_front({987654321, L});
    for(int i=0; i<N; ++i) {
        int n; cin>>n;
        if(dq.front().second==i)
            dq.pop_front();
        while(!dq.empty() && dq.back().first>=n ) {
            dq.pop_back();
        }
        dq.push_back({n, i+L});
        size++;

        cout<<dq.front().first<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}