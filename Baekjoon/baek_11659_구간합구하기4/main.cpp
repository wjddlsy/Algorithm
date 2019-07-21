#include <iostream>
using namespace std;
int pSum[100001], A[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    for(int i=1; i<=N; ++i){
        cin>>A[i];
        pSum[i]=pSum[i-1]+A[i];
    }
    for(int i=1; i<=M; ++i){
        int a, b;
        cin>>a>>b;
        cout<<pSum[b]-pSum[a-1]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}