#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> psum;
vector<vector<int>> board;

int gridSum(int y1, int x1, int y2, int x2){
    int ret=psum[y2][x2];
    if(y1>0) ret-=psum[y1-1][x2];
    if(x1>0) ret-=psum[y2][x1-1];
    if(y1>0 && x1>0) ret+=psum[y1-1][x1-1];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    psum=vector<vector<int>>(2*N+2, vector<int>(2*N+2, 0));
    board=vector<vector<int>>(2*N+2, vector<int>(2*N+2,0));
    map<int, int> X, Y;
    vector<int> xx, yy;
    int nx=0, ny=0;
    vector<pair<int, int>> points;

    for(int i=0; i<N; ++i){
        int x, y;
        cin>>x>>y;
        points.emplace_back(x,y);
        xx.emplace_back(x); yy.emplace_back(y);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());

    for(int i=0; i<N; ++i){
        X[xx[i]]=(++nx)*2-1; Y[yy[i]]=(++ny)*2-1;
    }
    for(auto &p:points){
        board[X[p.first]][Y[p.second]]++;
    }
    for(int i=1; i<=2*N; ++i){
        for(int j=1; j<=2*N; ++j){
            psum[i][j]=board[i][j];
            psum[i][j]+=psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1];
        }
    }

    int ret=987654321;
    for(int i=1; i<=2*N; ++i){
        for(int j=1; j<=2*N; ++j){
            if(i%2!=0 && j%2!=0)
                continue;
            int cow, cow1, cow2, cow3, cow4;
            cow1=gridSum(1, 1, i, j);
            cow2=gridSum(1, j, i, 2*N);
            cow3=gridSum(i, 1, 2*N, j);
            cow4=gridSum(i, j, 2*N, 2*N);
            cow=max({cow1, cow2, cow3, cow4});
            ret=min(ret, cow);
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}