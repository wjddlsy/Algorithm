#include <iostream>
#include <string.h>
using namespace std;

int board[1000];
int cache[1000][1000]; //최대 차이 저장..

int getdiff(int l, int r){
    if(l>r)
        return 0;
    int& ret=cache[l][r];
    if(ret!=-1)
        return ret;
    int cand1=board[l]-getdiff(l+1, r);
    int cand2=board[r]-getdiff(l, r-1);
    ret=max(cand1, cand2);
    return ret;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int sum=0;
        for(int i=0; i<N; ++i) {
            cin >> board[i];
            sum+=board[i];
        }
        memset(cache, -1, sizeof(cache));
        int diff=getdiff(0, N-1);
        cout<<(sum+diff)/2<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}