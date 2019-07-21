#include <iostream>
#include <cstring>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int N, M, start=0;
    cin>>N>>M;
    int street[1002];
    memset(street, 0, sizeof(street));
    for(int i=0; i<N; ++i){
        int D, W;
        cin>>D>>W;
        D++;
        street[D]=W;
        if(i==M-1)
            start=D;
    }
    vector<vector<vector<long long>>> cache(1002, vector<vector<long long>>(1002, vector<long long>(2, -1)));
//    int cache[1001][1001][2];
//    memset(cache, -1, sizeof(cache));
    long long psum[1002];
    memset(psum, 0, sizeof(psum));
    for (int i=1; i<=1001; ++i) {
        psum[i]=psum[i-1]+street[i];
    }

    const long long INF=987654321;

    function<long long(int,int,int)> dp = [&](int l, int r, int flag) {
        if(l==1 && r==1001)
            return 0ll;
        if(l==0)
            return INF;
        if(r==1002)
            return INF;
        long long &ret = cache[l][r][flag];
        if (ret != -1) return ret;
        ret=0;
        long long cost = psum[1001] - (psum[r] - psum[l-1]);
        int l_d = flag == 0 ? 1 : r-l+1;
        int r_d = flag == 0 ? r-l+1 : 1;
        long long right=INF, left=INF;
        left=dp(l-1, r, 0)+cost*l_d;
        right=dp(l, r+1, 1)+cost*r_d;
        ret = min(left, right);
        return ret;
    };

    cout << dp(start, start, 0);

    //std::cout << "Helong longo, World!" << std::endl;
    return 0;
}