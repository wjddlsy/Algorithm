#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin>>N>>Q;

    vector<int> psum(N+1, 0);
    for(int i=1; i<=N; ++i){
        cin>>psum[i];
        psum[i]^=psum[i-1];
    }
    int ans=0;
    while(Q--){
        int s, e;
        cin>>s>>e;
        ans^=(psum[e]^psum[s-1]);
    }
    cout<<ans;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}