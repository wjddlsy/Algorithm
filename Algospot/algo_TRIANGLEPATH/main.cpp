#include <iostream>
#include <string.h>
using namespace std;

int board[100][100];
int cache[100][100];

int path(const int& n, int y, int x){
    if(y==n-1) return board[y][x];
    int& ret=cache[y][x];

    if(ret!=-1){
        return ret;
    }

    ret=max(path(n, y+1, x), path(n, y+1, x+1)) + board[y][x];
    return ret;

}
int main() {
    int c;
    cin>>c;
    while(c--){
        memset(cache, -1, sizeof(cache));
        memset(board, 0, sizeof(board));
        int n;
        cin>>n;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=i; ++j){
                cin>>board[i][j];
            }
        }
        cout<<path(n, 0 ,0)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}