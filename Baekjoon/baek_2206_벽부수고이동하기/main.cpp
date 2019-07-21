#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char board[1000][1000];
int N, M;
int dx[]={0, 0, 1, -1}, dy[]={1,-1,0,0};

struct Point{
    int r, c, wall;
    Point(int r, int c, int wall):r(r),c(c), wall(wall){

    }
};

bool isRange(int r, int c){
    if(r<0 || r>=N || c<0 || c>=M)
        return false;
    return true;
}
int bfs(){
    queue<Point> q;
    int discovered[1000][1000][2];
    memset(discovered, -1, sizeof(discovered));
    q.push(Point(0, 0, 0));
    discovered[0][0][0]=1;
    while(!q.empty()){
        Point here=q.front();
        q.pop();
        if(here.r==N-1 && here.c==M-1){
            if(discovered[N-1][M-1][1]!=-1)
                return discovered[N-1][M-1][1];
            return discovered[N-1][M-1][0];
        }
        for(int i=0; i<4; ++i){
            Point there=Point(here.r+dx[i], here.c+dy[i], here.wall);
            if(!isRange(there.r, there.c))
                continue;
            if(discovered[there.r][there.c][there.wall]!=-1)
                continue;
            if(board[there.r][there.c]=='0'){
                q.push(Point(there.r, there.c, there.wall));
                discovered[there.r][there.c][there.wall]=discovered[here.r][here.c][here.wall]+1;
            }
            else {
                if(there.wall==0){
                    q.push(Point(there.r, there.c, 1));
                    discovered[there.r][there.c][1]=discovered[here.r][here.c][0]+1;

                }

            }

        }
    }
    return -1;
}
int main() {
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>board[i][j];
        }
    }
    cout<<bfs();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}