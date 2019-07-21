#include <iostream>
#include <vector>
using namespace std;

int N, T[1025][1025], A[1025][1025];

void update(int x, int y, int c){
    int nx=x;
    while(nx<=N){
        int ny=y;
        while(ny<=N){
            T[nx][ny]+=c;
            ny+=(ny&-ny);
        }
        nx+=(nx&-nx);
    }
}

int sum(int x, int y){
    int ret=0;
    int ny=y;
    while(ny>0){
        int nx=x;
        while(nx>0){
            ret+=T[nx][ny];
            nx&=(nx-1);
        }
        ny&=(ny-1);
    }
    return ret;
}

int solve(int x1, int y1, int x2, int y2){
    return sum(x2, y2)-sum(x2, y1-1)-sum(x1-1, y2)+sum(x1-1, y1-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M;
    cin>>N>>M;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin>>A[i][j];
            update(i, j, A[i][j]);
        }
    }
    int w;
    for(int i=1; i<=M; ++i){
        cin>>w;
        if(w==0) {
            int x, y, c;
            cin >> x >> y >> c;
            update(x, y, c-A[x][y]);
            A[x][y]=c;
        } else {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<solve(x1,y1,x2,y2)<<'\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}