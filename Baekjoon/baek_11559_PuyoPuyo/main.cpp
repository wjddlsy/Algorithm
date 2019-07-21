#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string board[12];
int visited[72];
int N;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool flag=false;
int cnt=0;
int ret=0;


bool isRange(int x, int y){
    if(x<0 || x>=12 || y<0 || y>=6){
        return false;
    }
    return true;
}

void print(){
    cout<<'\n';
    for(int i=0; i<12; ++i){
        for(int j=0; j<6; ++j){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}
void fall(){
    for(int i=0; i<6; ++i){
        for(int j=11; j>=0; --j){
            if(board[j][i]=='.')
                continue;
            int index=j;
            while(index<11 && board[index+1][i]=='.'){
                swap(board[index][i], board[index+1][i]);
                index++;
            }
        }
    }
}

void dfs(int here, char color){
    if(visited[here])
        return;
    visited[here]=true;
    cnt++;
    int x=here/6;
    int y=here%6;
    vector<pair<int, int>> coloring;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i], ny=y+dy[i];
        if(!isRange(nx, ny)) continue;
        if(board[nx][ny]==color){
            board[nx][ny]='.';
            dfs(nx*6+ny, color);
            coloring.push_back({nx, ny});
        }
    }
    if(cnt<4){
        for(auto p:coloring){
            board[p.first][p.second]=color;
        }
    }
}

void dfsAll(){
    flag=false;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<N; ++i){
        if(visited[i])
            continue;
        char color=board[i/6][i%6];
        if(color=='.')
            continue;
        board[i/6][i%6]='.';
        cnt=0;
        dfs(i, color);
        if(cnt<4)
            board[i/6][i%6]=color;
        else
            flag=true;
    }
}
int main() {
    N=12*6;
    for(int i=0; i<12; ++i){
        cin>>board[i];
    }

    while(true) {
        dfsAll();
        //print();
        if(!flag)
            break;
        ret++;
        fall();
    }

    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}