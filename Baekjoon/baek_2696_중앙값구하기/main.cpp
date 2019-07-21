#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int m; cin>>m;
        priority_queue<int, vector<int>, greater<>> minHeap;
        priority_queue<int> maxHeap;
        cout<<(m+1)/2<<'\n';
        for(int i=1; i<=m; ++i) {
            int n; cin>>n;
            if(maxHeap.size()==minHeap.size())
                maxHeap.push(n);
            else
                minHeap.push(n);
            if(!minHeap.empty() && !maxHeap.empty() && minHeap.top()<maxHeap.top()) {
                int a=maxHeap.top(), b=minHeap.top();
                minHeap.pop(); maxHeap.pop();
                maxHeap.push(b);
                minHeap.push(a);
            }
            if(i%2==1) {
                cout<<maxHeap.top()<<" ";
            }
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}