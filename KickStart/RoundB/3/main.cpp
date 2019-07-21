#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, S;
int A[100001];
int freq[100001], sum[100001];

int solve(){
    int ret=0;
    for(int i=1; i<=N; ++i){
        for(int j=i+1; j<=N; ++j){
            int cnt=sum[j]-sum[i-1];
            ret=max(ret, cnt);
        }
    }
    return ret;
}
int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>N>>S;
        unordered_map<int, int> m;
        memset(freq, 0, sizeof(freq));
        memset(sum, 0, sizeof(sum));
        for(int i=1; i<=N; ++i){
            cin>>A[i];
        }
        int ret=1;
        vector<vector<int>> freq(N, vector<int>(N, 0));
        for(int i=1; i<=N; ++i) freq[i][i]=1;

        for(int i=1; i<=N; ++i){
            unordered_map<int, int> m;

        }
        cout<<"Case #"<<t<<": "<<solve()<<'\n';
    }
    return 0;
}