#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

int N, L, R;
int board[50][50];
int dx[]={0,0,-1,1}, dy[]={1,-1,0,0};
int visited[50][50]={0};

void print(int (&array)[50][50]){
//    cout<<'\n';
//    for(int i=0; i<N; ++i){
//        for(int j=0; j<N; ++j){
//            cout<<array[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
}
bool isRange(pair<int, int> p){
    if(p.first<0 || p.first>=N || p.second<0 || p.second>=N)
        return false;
    return true;
}

void populate(){
    map<int, pair<int, int>> m;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int index=visited[i][j];
            m[index].first+=board[i][j];
            m[index].second++;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            int index=visited[i][j];
            board[i][j]=m[index].first/m[index].second;
        }
    }
}
void dfs(pair<int, int> here, int index){
    visited[here.first][here.second]=index;
    for(int i=0; i<4; ++i){
        pair<int, int> there={here.first+dx[i], here.second+dy[i]};
        if(!isRange(there))
            continue;
        if(visited[there.first][there.second]!=0)
            continue;
        int diff=abs(board[here.first][here.second]-board[there.first][there.second]);
        if(diff<=R && diff>=L) {
            visited[there.first][there.second] = index;
            dfs(there, index);
        }
    }
}

bool dfsAll(){
    int index=1;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) {
            if (visited[i][j]!=0)
                continue;
            dfs({i, j}, index);
            index++;
        }
    }
    if(index==N*N+1)
        return false;

    populate();
    return true;
}

int main() {
    cin>>N>>L>>R;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>board[i][j];
        }
    }
    int cnt=0;
    while(dfsAll()){
        cnt++;
    }
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}