#include <iostream>
#include <vector>

using namespace std;

bool board[101][101];

int main() {
    int n;
    cin>>n;
    for(int t=0; t<n; ++t) {
        int x, y;
        cin>>x>>y;
        for(int i=x; i<x+10; ++i) {
            for(int j=y; j<y+10; ++j) {
                board[j][i]=true;
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=101; ++i) {
        for(int j=1; j<=101; ++j) {
            if(board[i][j])
                cnt++;
        }
    }
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}