#include <iostream>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
#define INF 1e18

ll cache[2][101][101];
ll pos[101]; //거리를 좌표로 바꿈
int N, a;
ll go(int flag, int left, int right){
    if(left==1 && right==N)
        return 0;
    ll &ret=cache[flag][left][right];
    if(ret!=-1)
        return ret;
    ret=INF;
    ll mul=N-right+left-1, cost;
    if(left-1>=1){
        if(!flag) cost=mul*(pos[left]-pos[left-1]); //왼쪽으로 가기
        else cost=mul*(pos[right]-pos[left-1]); // 오른쪽에서 왼쪽으로 가기
        ret=min(ret, go(0, left-1, right)+cost);
    }
    if(right+1<=N){
        if(!flag) cost=mul*(pos[right+1]-pos[left]);
        else cost=mul*(pos[right+1]-pos[right]);
        ret=min(ret,go(1, left, right+1)+cost);
    }
    return ret;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(cache, -1, sizeof(cache));
        cin>>N>>a;
        for(int i=2; i<=N; ++i){
            cin>>pos[i];
            pos[i]+=pos[i-1];
        }
        cout << go(0,a,a)<<endl;
    }
    return 0;
}