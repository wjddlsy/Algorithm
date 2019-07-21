#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, K, L, cnt=0;
// -1은 아무것도 없는 것,
int board[100][100]; // -1은 아무 것도 없는 거, 1은 사과

char times[10001];
queue<pair<int, int>> foots;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

bool isRange(int y, int x){
    if(y>=N || y<0 || x>=N || x<0)
        return false;
    return true;
}

int head_y, head_x, tail_y, tail_x;

bool go(int dir){
    cnt ++ ;
    // 뱀대가리가 벅에 박는다
    if(!isRange(head_y, head_x))
        return false;
    if(board[head_y][head_x]!=-1 && board[head_y][head_x]!=4)
        return false;

    // 사과가 아닌 경우 꼬리의 앞에꺼가 변함,,
    if(board[head_y][head_x]!=4){
        board[head_y][head_x]=dir;
        board[tail_y][tail_x]=-1;

        foots.pop();
        tail_y=foots.front().second;
        tail_x=foots.front().first;

    }

        // 사과인 경우 꼬리의 앞에꺼는 변하지 않앙....
    else {
        board[head_y][head_x]=dir;
    }

    return true;

    // 머리를 다음칸으로 보내야됨 이제까지 했던건 가만히 내두면 돼요
    // dir 정하기는 필요가 없당!
    //go(head_y, head_x, tail_y, tail_x, dir);
}
int main() {
    cin>>N>>K;

    memset(board, -1, sizeof(board));
    for(int i=0; i<K; ++i){
        int y, x;
        cin>>y>>x;
        board[y-1][x-1]=4; // 사과!
    }

    board[0][0]=0; // 오른쪽을 바라보는 뱀대가리


    cin>>L;
    for(int i=0; i<L; ++i){
        int t;
        char dir;
        cin>>t>>dir;
        times[t]=dir;
    }

    int dir=0;
    foots.push({0,0});
    foots.push({1,0});

    head_y=0, head_x=1, tail_y=0, tail_x=0;
    while(go(dir)){
        if(times[cnt]=='L') // 왼쪽 90도 회전
            dir=(dir+3)%4;
        else if(times[cnt]=='D')
            dir=(dir+1)%4;
        head_y+=dy[dir]; //head 이동하기!!!!!!
        head_x+=dx[dir];

        foots.push({head_x, head_y});
    }

    cout << cnt;
}