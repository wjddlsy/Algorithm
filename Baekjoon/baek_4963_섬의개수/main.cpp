#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool adj[50][50], visited[50][50];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[] = {-1, 1, 0, -1, 1, 0, -1, 1}, h, w;

bool isRange(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void dfs(int x, int y) {
    if(visited[x][y])
        return;
    visited[x][y]=true;
    for(int i=0; i<8; ++i) {
        int nx=x+dx[i], ny=y+dy[i];
        if(!isRange(nx, ny) || !adj[nx][ny])
            continue;
        dfs(nx, ny);
    }
}

int dfsAll() {
    int cnt=0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(visited[i][j] || !adj[i][j])
                continue;
            dfs(i, j);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    while (true) {
        cin >> w >> h;
        if (h == 0 && w == 0)
            break;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> adj[i][j];
            }
        }
        cout<<dfsAll()<<'\n';
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}