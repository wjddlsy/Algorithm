#include <iostream>
#include <vector>
#include <set>
using namespace std;

string board[202];
int dx[]={0, 0, -1, 1}, dy[]={1, -1, 0, 0};
int parent[202*202], n, m;
bool visited[202*202];

void init() {
    for(int i=0; i<202*202; ++i) {
        parent[i]=i;
    }
}

int find (int u) {
    if(u==parent[u])
        return u;
    //cerr<<u<<'\n';
    return parent[u]=find(parent[u]);
}

void merge(int u, int v) {
    u=find(u);
    v=find(v);
    if(u==v)
        return;
    parent[u]=v;
}

bool isRange(int x, int y) {
    return x>=0 && x<m && y>=0 && y<n;
}
void dfs(int here) {
    if(visited[here])
        return;
    visited[here]=true;
    for(int i=0; i<4; ++i) {
        int x=here/n + dx[i], y=here%n + dy[i];
        if(!isRange(x, y))
            continue;
        int there=x*n+y;
        if(board[x][y]=='.' || board[x][y]=='B') {
            merge(here, there);
            dfs(there);
        }
    }
}

void dfsAll() {
    for(int i=0; i<n*m; ++i) {
        if(visited[i])
            continue;
        if(board[i/n][i%n]!='B')
            continue;
        dfs(i);
    }
}

int main() {
    double K;
    int N, M;
    cin>>N>>M>>K;
    n=2*N+1; m=2*M+1; // m: 행 n: 열
    K=K*2-1;
    for(int i=0; i<m; ++i) {
        cin>>board[i];
    }
    init();
    dfsAll();

    int x=m-1, y=K+1;

    set<int> ret;
    int ddx[2]={-1, 1}, ddy[2]={-1, 1};
    bool dirx=0, diry=0;

    while(x<=m-1) {
        if(x==0)
            dirx=(!dirx);
        if(y==0 || y==n-1)
            diry=(!diry);
        x+=ddx[dirx];
        y+=ddy[diry];
        if(x>=m)
            break;
        if(board[x][y]=='B' || board[x][y]=='.') {
            ret.insert(find(x*n+y));
        }
        if(board[x][y]=='-') {
            for(int i=0; i<2; ++i) {
                int nx=x+ddx[i];
                if(isRange(nx, y) && board[nx][y]=='B')
                    ret.insert(find(nx*n+y));
            }
        }
        if(board[x][y]=='|') {
            for(int i=0; i<2; ++i ){
                int ny=y+ddy[i];
                if(isRange(x, ny) && board[x][ny]=='B')
                    ret.insert(find(x*n+ny));
            }
        }
    }
    cout<<ret.size();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}