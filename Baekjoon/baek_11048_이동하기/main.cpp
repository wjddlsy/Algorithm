#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int board[1000][1000], N, M;
int cache[1000][1000];

int solve(int r, int c) {
    if(r >= N || c>=M)
        return 0;
    int& ret=cache[r][c];
    if(ret!=-1)
        return ret;
    ret = max({solve(r+1, c), solve(r, c+1), solve(r+1, c+1)}) + board[r][c];
    return ret;
}
int main() {
    cin>>N>>M;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin>>board[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}