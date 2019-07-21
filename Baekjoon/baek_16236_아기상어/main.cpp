#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int board[20][20];

int dx[]={0,-1,1,0}, dy[]={-1,0, 0, 1};

void print(){
    cout<<'\n';
    for(int i=0; i<N; ++i){
        for(int j=0;j <N; ++j){
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
}
bool isRange(pair<int, int> p){
    if(p.first<0 || p.first>=N || p.second<0 || p.second>=N)
        return false;
    return true;
}

int bfs(pair<int, int>& start, int sizeOfShark){
    queue<pair<int, int>> q;
    int discovered[20][20];
    memset(discovered, -1, sizeof(discovered));
    q.push(start);
    board[start.first][start.second]=0;
    discovered[start.first][start.second]=0;
    vector<pair<int, int>> shark;
    int time=987654321;
    while(!q.empty()){
        pair<int, int> here=q.front();
        int dist=discovered[here.first][here.second];
        q.pop();
        int fish=board[here.first][here.second];
        if(fish>0 && fish<sizeOfShark && time>=dist){
              shark.push_back(here);
              time=dist;
//            board[here.first][here.second]=-1;
//            board[start.first][start.second]=0;
            //print();
            continue;
        }
        else if(dist>time)
            break;
        for(int i=0; i<4; ++i){
            pair<int, int> there={here.first+dy[i], here.second+dx[i]};
            fish=board[there.first][there.second];
            if(!isRange(there))
                continue;
            if(discovered[there.first][there.second]!=-1)
                continue;
            if(fish>sizeOfShark)
                continue;
            q.push(there);
            discovered[there.first][there.second]=dist+1;
        }
    }

    if(time!=987654321){
        sort(shark.begin(), shark.end());
        board[shark[0].first][shark[0].second]=0;
        start=shark[0];
        return time;
    }

    return -1;
}


int main() {
    cin>>N;
    pair<int, int> start;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>board[i][j];
            if(board[i][j]==9)
                start={i, j};
        }
    }
    int cnt=0, sizeofShark=2, time=0;
    while(true){
        if(cnt==sizeofShark){
            cnt=0;
            sizeofShark++;
        }
        int dist=bfs(start, sizeofShark);
        if(dist==-1)
            break;
        cnt++;
        time+=dist;

    }
    cout<<time;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}