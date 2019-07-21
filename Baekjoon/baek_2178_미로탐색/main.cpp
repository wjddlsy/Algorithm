#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int N, M;
vector<string> box;
bool discovered[100][100];
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};

bool isRange(int x, int y){
    if(x<0 || x>=M || y<0 || y>=N)
        return false;
    return true;
}

int bfs(){
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()){
        int x, y, dist;
        tie(x, y, dist)=q.front();
        q.pop();
        for(int i=0; i<4; ++i){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx==M-1 && ny==N-1)
                return dist+2;
            if(discovered[ny][nx])
                continue;
            if(!isRange(nx, ny))
                continue;
            if(box[ny][nx]=='0')
                continue;
            q.push(make_tuple(nx, ny, dist+1));
            discovered[ny][nx]=true;

        }

    }
    return -1;
}
int main() {
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        string s;
        cin>>s;
        box.push_back(s);
    }
    cout<<bfs();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}