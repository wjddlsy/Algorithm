#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        int N, K;
        cin>>N>>K;
        vector<int> C(N), D(N);
        for(int i=0; i<N; ++i){
            cin>>C[i];
        }
        for(int i=0; i<N; ++i){
            cin>>D[i];
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}