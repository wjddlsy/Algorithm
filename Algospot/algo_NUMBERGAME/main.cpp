#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int INIT=-987654321;
int cache[50][50];

int play(vector<int>& board, int left, int right){
    if(left>right)
        return 0;
    int& ret=cache[left][right];
    if(ret!=INIT)
        return ret;
    ret=max(board[left]-play(board, left+1, right), board[right]-play(board, left, right-1));
    if(right-left+1>=2){
        ret=max(ret, -play(board, left+2, right));
        ret=max(ret, -play(board, left, right-2));
    }
    return ret;
}

int main() {
    int c;
    cin>>c;
    while(c--){
        int n;
        cin>>n;
        vector<int> board(n);
        for(int i=0; i<n; ++i){
            cin>>board[i];
        }
        for(int i=0; i<50; ++i){
            for(int j=0; j<50; ++j)
                cache[i][j]=INIT;
        }
        cout<<play(board, 0, n-1)<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}