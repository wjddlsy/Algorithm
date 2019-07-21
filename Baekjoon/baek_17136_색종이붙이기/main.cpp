#include <iostream>

using namespace std;
int board[10][10];
int ans=987654321, blockCnt=0;
int paperCnt[6]={0,5,5,5,5,5};

bool isRange(int r, int c){
    if(r<0 || r>=10 || c<0 || c>=10)
        return false;
    return true;
}

bool possible(int r, int c, int size){
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(!isRange(r+i, c+j)) return false;
            if(!board[r+i][c+j]) return false;
        }
    }
    return true;
}

void paint(int r, int c, int size){
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            board[r+i][c+j]=0;
        }
    }
}

void unpaint(int r, int c, int size){
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            board[r+i][c+j]=1;
        }
    }
}

void dfs(int r, int c, int cnt){

    if(cnt>ans){ // 이미 최솟값 구함
        return;
    }

    if(c==10){
        r++;
        c=0;
    }

    if(r==10){
        if(ans>cnt) ans=cnt;
        return;
    }


    // 1. 이 위치에서 색종이를 놓는당
    int maxSize=0;
    if(board[r][c]){
        for(int i=5; i>0; --i){
            if(possible(r, c, i)){
                maxSize=i;
                break;
            }
        }
        for(maxSize; maxSize>0; --maxSize){
            if(paperCnt[maxSize]){
                paint(r, c, maxSize);
                paperCnt[maxSize]--;
                dfs(r, c+1, cnt+1);
                paperCnt[maxSize]++;
                unpaint(r, c, maxSize);
            }

        }
    }
    // 2. 못놓는다면 그 다음으로
    else {
        dfs(r, c+1, cnt);
    }
}

int main(){
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            cin>>board[i][j];
        }
    }
    dfs(0,0,0);
    if(ans==987654321) cout<<-1;
    else cout<<ans;
    return 0;
}