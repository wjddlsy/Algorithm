#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int INF=987654321;

int n;
int A[101], pSum[101], pSqSum[101];

void precalc(){
    sort(A, A+n);
    pSum[0]=A[0];
    pSqSum[0]=A[0]*A[0];
    for(int i=0; i<n; ++i){
        pSum[i]=pSum[i-1]+A[i];
        pSqSum[i]=pSqSum[i-1]+A[i]*A[i];
    }
}

int minError(int lo, int hi){
    // 부분합을 이용해 A[lo]-A[hi]까지 합을 구한다.
    int sum=pSum[hi]-(lo==0?0:pSum[lo-1]);
    int sqSum=pSqSum[hi]-(lo==0?0:pSqSum[lo-1]);
    int m=int(0.5+(double)sum/(hi-lo+1));

    int ret=sqSum-2*m*sum+m*m*(hi-lo+1);
    return ret;

}

int cache[101][11];
int quantize(int from, int parts){
    if(from==n)
        return 0;
    if(parts==0)
        return INF;

    int& ret=cache[from][parts];
    if(ret!=-1) return ret;
    ret=INF;
    for(int partSize=1; from+partSize<=n; ++partSize){
        ret=min(ret, minError(from, from+partSize-1)+quantize(from+partSize, parts-1));
    }
    return ret;
}

int main() {
    int c;
    cin>>c;
    while(c--){
        int s;
        cin>>n>>s;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; ++i){
            cin>>A[i];
        }
        precalc();
        cout<<quantize(0,s)<<endl;

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}