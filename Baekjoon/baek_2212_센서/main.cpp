#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin>>N>>K;
    vector<int> positions(N);
    vector<int> diff(N-1);
    for(auto &pos:positions){
        cin>>pos;
    }
    sort(positions.begin(), positions.end());
    for(int i=0; i<N-1; ++i){
        diff[i]=positions[i+1]-positions[i];
    }
    sort(diff.begin(), diff.end(), greater<int>());
    int ret=0;
    for(int i=K-1; i<diff.size(); ++i){
        ret+=diff[i];
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}