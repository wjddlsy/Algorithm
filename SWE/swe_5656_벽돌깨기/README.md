# SWE 5656 벽돌 깨기

[링크][https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo&categoryId=AWXRQm6qfL0DFAUo&categoryType=CODE]



# Solve

## IDEA

## INFO

### 벡터 erase 시 주의 할 점

```
void pull(vector<vector<int>> &board){
    // board 돌면서 0인거 다 지우고 resize
    for(int x=0; x<W; ++x){
        for(auto it=board[x].begin(); it!=board[x].end();){
            if(*it==0)
                board[x].erase(it);
            else
                it++;

        }

        board[x].resize(H,0);
    }

}
```

==지우지 않았을 때만 iterator를 증가시켜주어야함!== 



## CODE

```c++
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int N, W, H, sum=987654321;
int dx[]={0,0,-1,1}, dy[]={-1,1,0,0}; // 상하좌우

// range check
bool isRange(int x, int y){
    if(x>=0 && y>=0 && x<W && y<H)
        return true;
    return false;
}

void print(vector<vector<int>>& board){
    for(int x=0; x<W; ++x){
        for(int y=0; y<H; ++y){
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
    cout<< endl;
}


void pull(vector<vector<int>> &board){
    // board 돌면서 0인거 다 지우고 resize
    for(int x=0; x<W; ++x){
        for(auto it=board[x].begin(); it!=board[x].end();){
            if(*it==0)
                board[x].erase(it);
            else
                it++;

        }

        board[x].resize(H,0);
    }

}

// 구슬 한 번 떨궜을 때 일어나는 일
void breaking(int x, int y, vector<vector<int>>& board){
    if(!isRange(x, y)) //범위 밖일 때
        return;
    int power=board[x][y];
    int nx, ny;
    board[x][y]=0;
    if(power>1){
        for(int dir=0; dir<4; ++dir){
            nx=x; ny=y;
            for(int p=0; p<power-1; ++p){
                nx+=dx[dir]; ny+=dy[dir];
                breaking(nx, ny, board);
            }
        }
    }
}


int find_top(int w, vector<vector<int>>& board){
    for(int y=H-1; y>=0; --y){
        if(board[w][y]!=0)
            return y;
    }
    return H-1;
}

int cal(vector<vector<int>> &board){
    int ret=0;
    for(int x=0; x<W; ++x){
        for(int y=0; y<H; ++y){
            if(board[x][y]!=0)
                ret++;
        }
    }
    return ret;
}


void pick(vector<vector<int>>& board, int w, int n){
    if(n==0) {
        sum=min(sum, cal(board));
        return;
    }
    vector<vector<int>> origin;
    for(int x=0; x<w; ++x){
        origin=board;
        breaking(x,find_top(x, board),board);
        pull(board);

        pick(board, w, n-1);
        board=origin;
    }

}

int main() {
    int t;
    cin>>t;
    for(int tn=1; tn<=t; ++tn){
        /*INPUT*/
        cin>>N>>W>>H;
        sum=987654321;
        vector<vector<int>> board(W, vector<int>(H,0));
        for(int i=H-1; i>=0; --i) {
            for (int j = 0; j < W; ++j) {
                cin >> board[j][i]; //x, y로 하기!!!!
            }

        }

        pick(board, W, N);

        cout <<"#"<<tn<<" "<<sum<<endl;
    }

    return 0;
}
```

