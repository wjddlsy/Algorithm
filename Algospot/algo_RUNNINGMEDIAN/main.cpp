#include <iostream>
#include <queue>
using namespace std;

int a, b, N;

int generator(int n){
    return ((n*(long long)a)+b)%20090711;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>N>>a>>b;
        int init=1983;

        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ret=init;
        maxHeap.push(init);
        for(int i=1; i<N; ++i){
            int next=generator(init);
            if(maxHeap.size()==minHeap.size())
                maxHeap.push(next);
            else
                minHeap.push(next);
            if(!minHeap.empty() && !maxHeap.empty() && minHeap.top()<maxHeap.top()){
                int a=maxHeap.top(), b=minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(b);
                minHeap.push(a);
            }
            init=next;
            ret=(ret+maxHeap.top())%20090711;
        }

        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}