#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> psum(N+1, 0);
        for(int i=1; i<=N; ++i){
            cin>>psum[i];
            psum[i]+=psum[i-1];
        }

        int ret=-987654321;
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=i; ++j){
                ret=max(ret, psum[i]-psum[j-1]);
            }
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}