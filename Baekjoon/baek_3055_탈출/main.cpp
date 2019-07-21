#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int R, C;
char board[50][50];
int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};

struct Point{
    int r, c;
    Point(){

    }
    Point(int r, int c):r(r), c(c){

    }

    Point operator+(Point p){
        return Point(r+p.r, c+p.c);
    }

    bool operator==(Point p){
        return r==p.r && c==p.c;
    }
};


bool isRange(Point p){
    if(p.r<0 || p.r>=R || p.c<0 || p.c>=C)
        return false;
    return true;
}


string bfs(Point d, Point s, vector<Point> w){
    queue<Point> water, hedgehog;
    int discoveredW[50][50], discoveredH[50][50];
    memset(discoveredH, -1, sizeof(discoveredH));
    memset(discoveredW, -1, sizeof(discoveredW));

    for(auto here:w){
        water.push(here);
        discoveredW[here.r][here.c]=0;
    }
    while(!water.empty()){
        Point here=water.front();
        int time=discoveredW[here.r][here.c];
        water.pop();
        for(int i=0; i<4; ++i){
            Point there=Point(here.r+dx[i], here.c+dy[i]);
            if(isRange(there) && discoveredW[there.r][there.c]==-1 && board[there.r][there.c]!='D' && board[there.r][there.c]!='X'){
                water.push(there);
                discoveredW[there.r][there.c]=time+1;
            }
        }
    }

    hedgehog.push(s);
    discoveredH[s.r][s.c]=0;
    while(!hedgehog.empty()){
        Point here=hedgehog.front();
        int time=discoveredH[here.r][here.c];
        if(here==d)
            return to_string(time);
        hedgehog.pop();
        for(int i=0; i<4; ++i){
            Point there=Point(here.r+dx[i], here.c+dy[i]);
            if(isRange(there) && discoveredH[there.r][there.c]==-1 && (discoveredW[there.r][there.c]==-1 || discoveredW[there.r][there.c]>time+1) && board[there.r][there.c]!='X'){
                hedgehog.push(there);
                discoveredH[there.r][there.c]=time+1;
            }

        }
    }
    return "KAKTUS";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>R>>C;
    Point d, s;
    vector<Point> w;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            cin>>board[i][j];
            if(board[i][j]=='D') {
                d.r = i;
                d.c = j;
            }
            else if(board[i][j]=='S'){
                s.r=i;
                s.c=j;
            }
            else if(board[i][j]=='*'){
                w.push_back(Point(i, j));
            }
        }
    }
    cout<<bfs(d, s, w);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}