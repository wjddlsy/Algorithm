#include <iostream>
#include <string.h>
using namespace std;

int board[101][101];
int cache[101][101];
int cache2[101][101];

//먼저 최적해를 구하깅
int go(int y, int x, const int& n){
    if(y==n-1)
        return board[y][x];
    int& ret=cache[y][x];
    if(ret!=-1) return ret;

    return ret=max(go(y+1, x, n), go(y+1, x+1, n))+board[y][x];

}

// 최댓값을 향해가는게 도대체 무엇인거신ㄱ
int count(int y, int x, const int& n){
    if(y==n-1)
        return 1;
    int& ret=cache2[y][x];
    if(ret!=-1) return ret;
    ret=0;
    // 어디로 가는게 이득인지
    if(go(y+1, x+1, n)>=go(y+1, x, n)) ret+=count(y+1, x+1,n);
    if(go(y+1, x+1,n)<=go(y+1, x, n)) ret+=count(y+1, x, n);
    return ret;

}

int main() {
    int c;
    cin>>c;
    while(c--){
        int n;
        cin>>n;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=i; ++j){
                cin>>board[i][j];
            }
        }
        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache));
        cout<<count(0, 0, n)<<endl;

    }
    return 0;
}