#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int visit[10][10][10][10]; // bfs 노드 왜? 왜노드지  아 visit 체크구나 ,,,,,,
int hx, hy; // 구멍 위치

pair<bool, bool> simulate(vector<string>&a, int k, int &x, int &y){
    if (a[x][y]=='.') return make_pair(false, false);
    int n=a.size();
    int m=a[0].size();
    bool moved=false;
    while(true){
        int nx=x+dx[x];
        int ny=y+dy[y];
        if(nx<0 || nx>=n || ny<0 || ny>=m)
            return make_pair(moved, false);
        if(a[nx][ny]=='#')
            return make_pair(moved, false);
        else if(a[nx][ny]=='R' || a[nx][ny]=='B'){
            return make_pair(moved, false);
        }
        else if (a[nx][ny]=='.'){
            swap(a[nx][ny], a[x][y]);
            x=nx;
            y=ny;
            moved=true;
        }
        else if(a[nx][ny]=='0'){
            a[x][y]='.';
            moved=true;
            return make_pair(moved, true);
        }
    }

    return make_pair(false, false);

}

pair<bool, bool> next(vector<string> a, int &rx, int &ry, int &bx, int &by, int dir){
    // 현재 구슬의 위치 체크
    a[rx][ry]='R';
    a[bx][by]='B';
    bool hole1=false, hole2=false; // 아직 안빠짐
    while(true){
        auto p1=simulate(a, dir, rx, ry);
        auto p2=simulate(a, dir, bx, by);
        if(p1.first==false && p2.first==false){ // 두 구슬 다 움직일 수 업을때 까지!
            break;
        }
        if(p1.second) hole1=true;
        if(p2.second) hole2=true;
    }
    return make_pair(hole1, hole2);
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n); // 4개: rx, ry, bx, by
    // 입력 받는 부분
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    int ans=-1;
    queue<tuple<int, int, int, int>> q; //방문 저장 큐
    int rx, ry,bx,by; //rx, ry, bx, by 맨 처음 노드!

    // a = 보드판 R, B, 위치 찾으러가기 & 빨간공 파란공 위치만 저장하구 빈칸으로 바꿈
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(a[i][j]=='O'){
                hx=i; hy=j;
            }
            else if(a[i][j]=='R'){
                rx=i; ry=j;
                a[i][j]='.';
            }
            else if(a[i][j]=='B'){
                bx=i; by=j;
                a[i][j]='.';
            }
        }
    }

    memset(visit, -1, sizeof(visit)); // visit 배열 초기화
    q.emplace(rx, ry, bx, by);
    visit[rx][ry][bx][by]=0;
    bool found=false;
    while(!q.empty()){ // 방문 방문~~ bfs
        tie(rx, ry, bx, by)=q.front();
        q.pop();
        for(int k=0; k<4; ++k){ // 4방향 방문... bfs bfs bsfs
            bool hole1, hole2; //빨강 파랑이 구멍에 빠졌는지
            int nrx=rx, nry=ry, nbx=bx, nby=by;
            tie(hole1, hole2)=next(a, nrx, nry, nbx, nby, k); // 기울이는 동작
            if(hole2) continue; // 파란 공 빠지면 실패니까
            if(hole1){
                found=true;
                ans=visit[rx][ry][bx][by]+1;
                break;
            }
            if(visit[nrx][nry][nbx][nby]!=-1) continue; // 방문했던 곳이라면 굳이 더 할 필요 없다.
            q.emplace(nrx, nry, nbx, nby);
            visit[nrx][nry][nbx][nby]=visit[rx][ry][bx][by]+1;
        }

        if(found)
            break;
    }

    cout << ans<<'\n';

    return 0;

}