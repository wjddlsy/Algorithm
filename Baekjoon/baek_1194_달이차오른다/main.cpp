#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

int N, M, START;
map<int, bool> END;

int dx[]={0, 0, -1, 1}, dy[]={-1, 1, 0, 0};
char board[50][50];

bool isRange(int r, int c) {
    return r>=0 && r<N && c>=0 && c<M;
}

int bfs(){
    queue<pair<int, int>> q; // position, key status
    vector<vector<int>> discovered(N*M, vector<int>(1<<6, -1));
    q.push({START, 0});
    discovered[START][0]=0;
    while(!q.empty()) {
        pair<int, int> here=q.front();
        int hereRow=here.first/M, hereCol=here.first%M;
        q.pop();
        if(END[here.first]){
            return discovered[here.first][here.second];
        }
        for(int i=0; i<4; ++i){
            pair<int, int> there=here;

            int thereRow=hereRow+dx[i], thereCol=hereCol+dy[i];
            there.first=thereRow*M+thereCol;

            if(!isRange(thereRow, thereCol))
                continue;
            if(discovered[there.first][there.second]!=-1)
                continue;
            if(board[thereRow][thereCol]=='#')
                continue;
            if(board[thereRow][thereCol]>='A' && board[thereRow][thereCol]<='F'){
                int key=board[thereRow][thereCol]-'A';
                if( !(there.second & (1<<key)) )
                    continue;
            }
            if(board[thereRow][thereCol]>='a' && board[thereRow][thereCol]<='f'){
                int key=board[thereRow][thereCol]-'A';
                there.second |= (1<<key);
            }

            q.push(there);
            discovered[there.first][there.second]=discovered[here.first][here.second]+1;

        }
    }
    return -1;
}
int main() {
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>board[i][j];
            int index=i*M+j;
            if(board[i][j]=='0')
                START=index;
            else if(board[i][j]=='1')
                END[index]=true;
        }
    }
    cout<<bfs();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}