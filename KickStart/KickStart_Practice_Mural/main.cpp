#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        int N;
        cin>>N;
        vector<int> preSum(N+1, 0);

        string s;
        cin>>s;
        for(int i=1; i<=N; ++i){
            preSum[i]=preSum[i-1]+s[i-1]-'0';
        }
        int length=(N+1)/2;
        int ret=0;
        for(int i=0; i+length<=N; ++i){
            int sum=preSum[i+length]-preSum[i];
            ret=max(ret, sum);
        }
        cout<<"Case #"<<t<<": "<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}