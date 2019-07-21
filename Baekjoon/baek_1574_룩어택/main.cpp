#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R, C, N;
int board[300][300];
int adj[300][300];
int aMatch[300], bMatch[300];
bool visited[600];
void placeRooks(){
    for(int y=0; y<R; ++y){
        for(int x=0; x<C; ++x){
            if(board[y][x]==0)
                adj[y][x]=1;
        }
    }
}

bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=0; b<C; ++b){
        if(adj[a][b]){
            if(bMatch[b]==-1 || dfs(bMatch[b])){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
            }
        }
    }
    return false;
}
int bipartiteMatch(){
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int ret=0;
    for(int i=0; i<R; ++i){
        memset(visited, false, sizeof(visited));
        ret+=dfs(i);
    }
    return ret;
}
int main() {
    cin>>R>>C>>N;
    for(int i=0; i<N; ++i){
            int r, c;
            cin>>r>>c;
            r--; c--;
            board[r][c]=1;

    }
    placeRooks();
    cout<<bipartiteMatch();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}