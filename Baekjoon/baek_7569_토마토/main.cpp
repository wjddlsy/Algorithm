#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;
int box[100][100][100];
int discovered[100][100][100];
int dx[6]={0,0,0,0,1,-1}, dy[6]={1,-1, 0, 0, 0,0}, dz[6]={0,0, 1, -1, 0, 0};
queue<tuple<int, int, int>> q;

bool isRange(int x, int y, int z){
    if(x<0 || x>=M || y<0 || y>=N || z<0 || z>=H)
        return false;
    return true;
}

int bfs(int total, int mature){
    if(total==mature)
        return 0;
    while(!q.empty()){
        tuple<int, int, int> here=q.front();
        int x, y, z;
        tie(x, y, z)=here;
        q.pop();
        if(box[z][y][x]) {
            for (int i = 0; i < 6; ++i) {
                int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
                if (!isRange(nx, ny, nz))
                    continue;
                if(discovered[nz][ny][nx])
                    continue;
                if (box[nz][ny][nx] == 0) {
                    q.push(make_tuple(nx, ny, nz));
                    box[nz][ny][nx] = box[z][y][x]+1;
                    mature++;
                    if (total == mature)
                        return box[nz][ny][nx]-1;
                }
            }
        }
    }
    return -1;
}

int main() {
    cin>>M>>N>>H;
    int total=0, mature=0;
    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                cin>>box[i][j][k];
                if(box[i][j][k]==1){
                    mature++;
                    q.push(make_tuple(k, j, i));
                    discovered[i][j][k]=1;
                }
                if(box[i][j][k]>=0){
                    total++;
                }
            }
        }
    }
    cout<<bfs(total, mature);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}