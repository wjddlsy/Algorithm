#include <iostream>
#include <queue>
using namespace std;

int box[1000][1000];
bool discoverd[1000][1000];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int N, M;

queue<pair<int, int>> q;

int bfs(int total, int n){
    if(total==n)
        return 0;
    int ret=-1;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        discoverd[x][y]=true;
        q.pop();
        if(box[x][y]==0)
            continue;
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=N || nx<0 || ny>=M || ny<0)
                    continue;
                if(discoverd[nx][ny] || box[nx][ny]==-1)
                    continue;
                discoverd[nx][ny]=true;
                if(box[nx][ny]==0) {
                    n++; box[nx][ny]=box[x][y]+1;
                }
                q.push({nx, ny});
                if(total==n)
                    return box[nx][ny]-1;
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>M>>N;
    int total=0, mature=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>box[i][j];
            if(box[i][j]==1) {
                q.push({i, j});
                mature++;
                total++;
            }
            if(box[i][j]==0)
                total++;
        }
    }
    cout<<bfs(total, mature);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}