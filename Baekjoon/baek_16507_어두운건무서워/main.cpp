#include <iostream>
#include <vector>

using namespace std;

int R, C, Q;

int gridSum(const vector<vector<int>>& psum, int y1, int x1, int y2, int x2){
    int ret=psum[y2][x2];
    if(y1>0) ret-=psum[y1-1][x2];
    if(x1>0) ret-=psum[y2][x1-1];
    if(y1>0 && x1>0) ret+=psum[y1-1][x1-1];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> Q;
    vector<vector<int>> psum(R+1, vector<int>(C+1,0));
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            int a; cin>>a;
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+a;
        }
    }
    for (int i = 0; i < Q; ++i) {
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<gridSum(psum, r1, c1, r2, c2)/((r2-r1+1)*(c2-c1+1))<<'\n';
    }
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}