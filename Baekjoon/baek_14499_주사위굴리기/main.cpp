#include <iostream>
#include <vector>

using namespace std;


int N, M, x, y, K;

void swap(int& a, int& b){
    int tmp=a;
    a=b;
    b=tmp;
}

bool isRange(int x, int y){
    if(x<0 || y<0 || x>=M || y>=N)
        return false;
    return true;
}

int main() {
    int board[21][21];
    int dice[4]={0,0,0,0};
    int up=0, down=0;
    int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, -1, 1}; // 동서북남

    cin>>N>>M>>y>>x>>K;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>board[i][j];
        }
    }



    for(int i=0; i<K; ++i){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int dir;
        cin>>dir;
        dir--;
        x+=dx[dir], y+=dy[dir];
        if(isRange(x, y)){

            switch(dir){
                case 0: // 동쪽
                    swap(up, dice[1]);
                    swap(down, dice[0]);
                    swap(up, down);
                    break;
                case 1: // 서쪽
                    swap(up, dice[0]);
                    swap(down, dice[1]);
                    swap(up, down);
                    break;
                case 2: // 북쪽
                    swap(up, dice[3]);
                    swap(down, dice[2]);
                    swap(up, down);
                    break;
                case 3:
                    swap(up, dice[2]);
                    swap(down, dice[3]);
                    swap(up, down);
                    break;
            }

            if(board[y][x]==0){
                board[y][x]=down;
            }
            else {
                down=board[y][x];
                board[y][x]=0;
            }

            cout << up << " ";
        }
        else {
            x-=dx[dir], y-=dy[dir];
        }


    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}