#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int i=0; i<n; ++i) {
        int x; cin>>x;
        if(x==0) {
            if(pq.empty()) {
                cout<<0;
            } else {
                cout << pq.top().first*pq.top().second;
                pq.pop();
            }
            cout<<'\n';
        }
        else
            pq.push({abs(x), x<0?-1:1});
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}