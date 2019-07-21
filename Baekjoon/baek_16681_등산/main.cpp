#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, D, E;
vector<int> h;

int main() {
    cin>>N>>M>>D>>E;
    h.resize(N);
    for(int i=0; i<N; ++i){
        cin>>h[i];
    }

    for(int i=0; i<M; ++i){
        int a, b, n;
        cin>>a>>b>>n;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}