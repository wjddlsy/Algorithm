#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> weights(N);
    for(auto &weight:weights) {
        cin>>weight;
    }

    sort(weights.begin(), weights.end());
    int ret=0;
    for(int i=0; i<N; ++i){
        ret=max(ret, (N-i)*weights[i]);
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}