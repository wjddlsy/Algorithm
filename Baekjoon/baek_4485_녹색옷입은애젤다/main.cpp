#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
const int INF=987654321;
int board[125][125];
int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
bool isRange(pair<int, int> pos){
    if(pos.first<0 || pos.first>=N || pos.second<0 || pos.second>=N)
        return false;
    return true;
}
int dijikstra(){
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    pq.push({-board[0][0],{0, 0}});
    dist[0][0]=board[0][0];
    while(!pq.empty()){
        pair<int, int> here=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(dist[here.first][here.second]<cost)
            continue;
        for(int i=0; i<4; ++i){
            pair<int, int> there={here.first + dx[i], here.second+dy[i]};
            if(!isRange(there))
                continue;
            int nextDist=cost+board[there.first][there.second];
            if(nextDist<dist[there.first][there.second]){
                dist[there.first][there.second]=nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dist[N-1][N-1];
}
int main() {
    int t=1;
    while(true){
        cin>>N;
        if(N==0)
            break;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cin>>board[i][j];
            }
        }
        cout<<"Problem "<<t<<": "<<dijikstra()<<'\n';
        ++t;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}