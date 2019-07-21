#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

string board[100];
int row[100][100], col[100][100];
vector<int> adj[10000];
int aMatch[10000], bMatch[10000];
bool visited[10000];
int rowCnt=1, colCnt=1;

int N;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(auto b:adj[a]){
            if(bMatch[b]==-1 || dfs(bMatch[b])){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
            }
    }
    return false;
}
int bipartiteMatch(){
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int ret=0;
    for(int i=0; i<rowCnt; ++i){
        memset(visited, false, sizeof(visited));
        ret+=dfs(i);
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>board[i];
    }


    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(board[i][j]!='.') continue;
            if(j==0 || row[i][j-1]==0)
                row[i][j]=rowCnt++;
            else if(row[i][j-1]!=0)
                row[i][j]=row[i][j-1];
        }
    }

    for(int j=0; j<N; ++j){
        for(int i=0; i<N; ++i){
            if(board[i][j]!='.') continue;
            if(i==0 || col[i-1][j]==0)
                col[i][j]=colCnt++;
            else if(col[i-1][j]!=0)
                col[i][j]=col[i-1][j];
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(board[i][j]!='.') continue;
            int a=row[i][j], b=col[i][j];
            adj[a].push_back(b);
        }
    }

    cout<<bipartiteMatch();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}