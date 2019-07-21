#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> weights(N);
    for(auto &weight:weights) {
        cin>>weight;
    }
    sort(weights.begin(), weights.end());

    int ret=0;
    for(auto &weight:weights) {
        if(weight>ret+1)
            break;
        ret+=weight;
    }
    cout<<ret+1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}