#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    for(auto &a:A){
        cin>>a;
    }
    sort(A.begin(), A.end());
    int maxVal=0;

    do {
        int val=0;
        for(int i=0; i<N-1; ++i){
            val+=abs(A[i]-A[i+1]);
        }
        maxVal=max(maxVal, val);
    } while(next_permutation(A.begin(), A.end()));

    cout<<maxVal;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}