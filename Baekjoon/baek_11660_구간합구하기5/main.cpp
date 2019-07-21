#include <iostream>
#include <vector>

using namespace std;

int N, M;

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
    cin >> N >> M;
    vector<vector<int>> psum(N+1, vector<int>(N+1,0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int a; cin>>a;
            psum[i][j]+=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+a;
        }
    }
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout<<gridSum(psum, x1, y1, x2, y2)<<'\n';
    }
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}