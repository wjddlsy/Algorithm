#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> psum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin>>psum[i];
        psum[i]+=psum[i-1];
    }
    int M;
    cin>>M;
    while(M--){
        int i, j;
        cin>>i>>j;
        cout<<psum[j]-psum[i-1]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}