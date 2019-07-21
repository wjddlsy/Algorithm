#include <iostream>
#include <math.h>
using namespace std;

int N, R, C, cnt=0;
void find(int r, int c, int n){
    if(r==R && c==C){
        cout << cnt;
        return;
    }

    if(R<r+n && R>=r && C<c+n && C>=c){
        find(r, c, n/2);
        find(r, c+n/2, n/2);
        find(r + n/2, c, n/2);
        find(r + n/2, c + n/2, n/2);
    }

    else{
        cnt+=n*n;
    }

}
int main() {
    cin>>N>>R>>C;
    // 1. 몇번째 행인지 찾기
    //int cnt=0;
    find(0,0, (int)pow(2,N));
    return 0;
}