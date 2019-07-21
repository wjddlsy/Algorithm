#include <iostream>
#include <vector>

using namespace std;
int dx[]={1, -1, -1, 1}, dy[]={1, 1, -1, -1};
int board[20][20];
int n;
bool isRange(int x, int y){
    if(x>=0 || x<n || y>=0 || y<n)
        return true;
    return false;
}

int make_path(const int& sx, const int& sy, int type){
    // 시계방향으로 돌기
    // 끝까지 먼저 감
    int x=sx, y=sy;
    // 시작점으로 돌아올 때 까지
    bool desserts[101];
    int dir=0;
    while(!(sx==x && sy==y)){
        int nx=x+dx[dir], ny=y+dy[dir];
        if(!isRange(nx, ny)){
            dir++;
            nx=x+dx[dir]; ny=y+dy[dir];
        }
        if(!desserts[board[ny][nx]]){ // 먹었떤 디저트인지 체크
            desserts[board[ny][nx]]=true;
            x=nx;
            y=ny;
        }
        else { //먹었던 디저트
            dir++;
        }

    }
}
void simulate(int n){
    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            // 시작점 설정
            make_path(x, y, 0);
        }
    }
}
int main() {
    int t;
    cin>>t;
    for(int nt=1; nt<=t; ++nt){
        cin >> n;
        for(int i=0; i<n; ++i){
            for (int j=0; j<n; ++j)
                cin>>board[i][j];
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}