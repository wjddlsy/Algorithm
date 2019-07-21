#include <iostream>
#include <vector>

using namespace std;

int R, C, dx[]={0,0,-1,1}, dy[]={1,-1,0,0};
string board[20];
bool visited[20][20], used[26];

bool isRange(int r, int c){
    return r>=0 && r<R && c>=0 && c<C;
}

int dfs(int r, int c, int sum) {
    int ret=sum;
    for(int i=0; i<4; ++i){
        int nr=r+dx[i], nc=c+dy[i];
        if(!isRange(nr, nc))
            continue;
        if(visited[nr][nc] | used[board[nr][nc]-'A'])
            continue;
        visited[nr][nc]=true;
        used[board[nr][nc]-'A']=true;
        ret=max(ret,dfs(nr, nc, sum+1));
        visited[nr][nc]=false;
        used[board[nr][nc]-'A']=false;
    }
    return ret;
}

int main() {
    cin>>R>>C;
    for(int i=0; i<R; ++i){
        cin>>board[i];
    }
    cout<<dfs(-1, 0, 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}