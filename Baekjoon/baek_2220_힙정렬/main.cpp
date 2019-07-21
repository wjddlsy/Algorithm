#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> heap(n);
    for(int i=1; i<n; ++i) {
        for(int j=i; j>1; j/=2)
            heap[j]=heap[j/2];
        heap[1]=i+1;
    }
    a[n]=1;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}