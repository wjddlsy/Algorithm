#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int cache[100000][5][5];
vector<int> board;

int go(int n, int left, int right){
    if(n==board.size())
        return 0;
    int& ret=cache[n][left][right];
    if(ret!=-1)
        return ret;
    ret=987654321;
    if(left==board[n]){
        return ret=1+go(n+1, left, right);
    }
    if(right==board[n]){
        return ret=1+go(n+1, left, right);
    }
    //왼발을 움직이는 경우
    if(left==0)
        ret=min(ret, 2+go(n+1, board[n], right));
    else {
        if(abs(left-board[n])==2)
            ret=min(ret, 4+go(n+1, board[n], right));
        if(abs(left-board[n])==1 || abs(left-board[n])==3)
            ret=min(ret, 3+go(n+1, board[n], right));
    }
    //오른발을 움직이는 경우
    if(right==0)
        ret=min(ret, 2+go(n+1, left, board[n]));
    else {
        if(abs(right-board[n])==2)
            ret=min(ret, 4+go(n+1, left, board[n]));
        if(abs(right-board[n])==1 || abs(right-board[n])==3)
            ret=min(ret, 3+go(n+1, left, board[n]));
    }

    return ret;

}
int main() {
    int in;
    while(true){
        cin>>in;
        if(in==0)
            break;
        board.push_back(in);
    }
    memset(cache,-1, sizeof(cache));
    cout<<go(0, 0, 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}