# SWE 5665 줄기세포 배양

# Solve

## IDEA

## INFO

### 리스트 지우기 !!!!!!!! 

```c++
void kill(int t){
    int y,x;

    for(auto it=cells.begin(); it!=cells.end(); ) {
        tie(x, y) = (*it);
        if (check[y][x] == 2 && board[y][x] == t) {
            check[y][x] = 3;
            cells.erase(it++);
        } else
            it++;
    }

}
```

==vector랑 다르당!==



## CODE

```c++
#include <iostream>
#include <list>
#include <string.h>
#include <tuple>
#define MAX 1000
using namespace std;

int N, M, K;

// 죽는 초 기록
int board[MAX][MAX];
// power 기록
int power[MAX][MAX];
// 0: 빈칸 1: 비활성 2: 활성 3: 뒤짐 4: 임시
int check[MAX][MAX];

int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
list<pair<int, int>> cells;

void print(){
    for(int i=0; i<MAX; ++i){
        for(int j=0; j<MAX; ++j){
            cout << check[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void activate(int t){
    int y,x;
    for(auto c:cells){
        tie(x,y)=c;
        if(check[y][x]==1 && board[y][x]==t){
            check[y][x]=2;
            board[y][x]=t+power[y][x];
        }
    }
}

void find_max(int x, int y, int t){
    for(int dir=0; dir<4; ++dir){
        int nx=x+dx[dir], ny=y+dy[dir];
        if(check[ny][nx]==2){
            power[y][x]=max(power[y][x], power[ny][nx]);
            board[y][x]=t+power[y][x];
            check[y][x]=1;
        }
    }
}
void spread(int t){
    int y, x;
    list<pair<int, int>> tmp=cells;
    for(auto c:tmp){
        tie(x, y)=c;
        if(check[y][x]==2){
            for(int dir=0; dir<4; ++dir){
                int nx=x+dx[dir], ny=y+dy[dir]; //퍼질 곳!
                if(check[ny][nx]==0){
                    find_max(nx, ny, t);
                    cells.push_back({nx,ny});
                }
            }
        }

    }
}

void kill(int t){
    int y,x;

    for(auto it=cells.begin(); it!=cells.end(); ) {
        tie(x, y) = (*it);
        if (check[y][x] == 2 && board[y][x] == t) {
            check[y][x] = 3;
            cells.erase(it++);
        } else
            it++;
    }

}

int cal(){
    return cells.size();
}
int main() {
    int t;
    cin>>t;
    for(int nt=1; nt<=t; ++nt){
        cells.clear();
        memset(board, 0, sizeof(board));
        memset(check, 0, sizeof(check));
        memset(power, 0, sizeof(power));
        cin>>N>>M>>K;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                int in;
                cin >> in;
                board[MAX/2+i][MAX/2+j]=in;
                power[MAX/2+i][MAX/2+j]=in;
                if(in>0) {
                    check[MAX / 2 + i][MAX / 2 + j] = 1;
                    cells.push_back({MAX/2+j,MAX/2+i});
                }
            }
        }

        //t초 배양

        for(int t=0; t<=K; ++t){
            
            spread(t);
            activate(t);
            kill(t);


        }

        cout << "#" << nt << " " << cal() << endl;
    }
    return 0;
}
```

