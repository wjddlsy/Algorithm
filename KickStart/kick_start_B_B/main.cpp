#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int R, C;
char board[250][250];
int dr[4]={1, -1, 0, 0}, dc[4]={0, 0, -1, 1};

bool isRange(int r, int c){
    if(r<0 || r>=R || c<0 || c>=C)
        return false;
    return true;
}

int bfs(vector<pair<int, int>>& chicken){
    int K=0;
    queue<pair<int, int>> q;
    int discovered[250][250];
    memset(discovered, -1, sizeof(discovered));
    for(auto ch:chicken){
        int r, c;
        tie(r,c)=ch;
        q.push(ch);
        discovered[r][c]=0;
    }
    while(!q.empty()){
        int r, c;
        tie(r, c)=q.front();
        q.pop();
        for(int i=0; i<4; ++i){
            int nr=r+dr[i], nc=c+dc[i];
            if(isRange(nr, nc) && discovered[nr][nc]==-1){
                q.push({nr, nc});
                discovered[nr][nc]=discovered[r][c]+1;
                K=max(K, discovered[nr][nc]);
            }
        }
    }
    return K;
}

int check(int K){
    
}
int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>R>>C;
        vector<pair<int, int>> chicken;
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                cin>>board[i][j];
                if(board[i][j]=='1')
                    chicken.push_back({i, j});
            }
        }
        int K=bfs(chicken);
        cout<<K<<'\n';
    }


    return 0;
}