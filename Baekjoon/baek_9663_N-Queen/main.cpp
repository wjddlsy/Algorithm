#include <iostream>
using namespace std;

int N, col[15], ret=0;

bool canPut(int r) {
    for(int i=0; i<r; ++i) {
        if(col[i]==col[r] || abs(col[i]-col[r])==(r-i))
            return false;
    }
    return true;
}
void solve(int r){
    if(r==N) {
        ret++;
        return;
    }
    for(int i=0; i<N; ++i){
        col[r]=i;
        if(canPut(r))
            solve(r+1);
    }
}
int main() {
    cin>>N;
    solve(0);
    cout<<ret;
}