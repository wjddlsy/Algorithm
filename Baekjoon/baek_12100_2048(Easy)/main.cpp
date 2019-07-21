#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
int N, ret=0;
bool chk[20][20];

bool isRange(int y, int x){
    if(x<0 || y<0 || y>=N || x>=N)
        return false;
    return true;
}

void go(int y, int x, int dir, int val, int board[][20]){

    int ny=y+dy[dir];
    int nx=x+dx[dir];

    if(!isRange(ny, nx))
        return;
    if(board[ny][nx]!=val && board[ny][nx]!=0)
        return;
    if(chk[ny][nx]){
        return;
    }

    if(board[ny][nx]==0){
        board[ny][nx]=val;
        board[y][x]=0;
    }

    else if(board[ny][nx]==val){
        board[ny][nx]+=val;
        board[y][x]=0;
        ret=max(ret, board[ny][nx]);
        chk[ny][nx]=true;
        return;
    }

    go(ny, nx, dir, board[ny][nx], board);
}


void pick(int toPick, int board[][20]){
    if(toPick==0) {
        return;
    }

    int origin[20][20];

    for(int dir=0; dir<4; ++dir){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                origin[i][j]=board[i][j];
            }
        }

        for(int r=0; r<N; ++r) {
            memset(chk, 0, sizeof(chk));
            switch (dir) {
                case 0: //상 x좌표 옮기기
                    for (int y = 0; y < N; ++y) {
                        go(y, r, 0, board[y][r], board);
                    }
                    break;
                case 1: // 하 x좌표 옮기기
                    for (int y = N-1; y >= 0; --y) {
                        go(y, r, 1, board[y][r], board);
                    }
                    break;
                case 2: //좌 y좌표 옮기기
                    for (int x = 0; x < N; ++x) {
                        go(r, x, 2, board[r][x], board);
                    }
                    break;
                case 3: //우
                    for (int x = N-1; x >=0 ; --x) {
                        go(r, x, 3, board[r][x], board);
                    }
                    break;
            }
        }
        pick(toPick-1, board);

        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                board[i][j]=origin[i][j];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int board[20][20];
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) {
            cin >> board[i][j];
            ret=max(ret, board[i][j]);
        }
    }

    pick(5, board);

    cout << ret;
    return 0;
}