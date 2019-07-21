#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[50][50], dx[4]={0, 0, -1, 1}, dy[4]={1, -1, 0, 0}, n;
const int INF=987654321;

bool isRange(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}
int main() {
    cin>>n;
    for(int i=0; i<n; ++i ){
        for(int j=0; j<n; ++j ){
            scanf("%1d", &board[i][j]);
            board[i][j]==0?board[i][j]=1:board[i][j]=0;
        }
    }
    vector<int> dist(n*n, INF);
    dist[0]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        for(int i=0; i<4; ++i) {
            int nx=here/n+dx[i], ny=here%n+dy[i];
            if(!isRange(nx, ny))
                continue;
            int there=nx*n+ny;
            int nextDist=cost+board[nx][ny];
            if(dist[there]>nextDist) {
                dist[there]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    cout<<dist[n*n-1];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}