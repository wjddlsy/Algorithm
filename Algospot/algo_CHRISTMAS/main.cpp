#include <iostream>
#include <vector>

using namespace std ;

int N, K;

int waysToBuy(const vector<int>& sum){
    const int MOD=20091101;
    int ret=0;
    vector<long long> count(K, 0);
    for(int i=0; i<=N; ++i){
        count[sum[i]]++;
    }
    for(int i=0; i<K; ++i){
        if(count[i]>=2)
            ret=(ret+((count[i]*(count[i]-1))/2))%MOD;
    }
    return ret;
}

int maxBuys(const vector<int>& sum){
    vector<int> ret(N+1, 0);
    vector<int> prev(K, -1);
    for(int i=0; i<=N; ++i){
        if(i>0)
            ret[i]=ret[i-1];
        else
            ret[i]=0;
        int loc=prev[sum[i]];
        if(loc!=-1) ret[i]=max(ret[i], ret[loc]+1);
        prev[sum[i]]=i;
    }
    return ret.back();
}
int main() {
    int T;
    cin>>T;

    while(T--){
        cin>>N>>K;
        vector<int> sum(N+1, 0);
        for(int i=1; i<=N; ++i){
            int d;
            cin>>d;
            sum[i]=(sum[i-1]+d)%K;
        }
        cout<<waysToBuy(sum)<<" "<<maxBuys(sum)<<endl;

    }
   //std::cout << "Hello, World!" << std::endl;
    return 0;
}