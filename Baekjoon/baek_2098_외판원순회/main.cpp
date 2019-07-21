#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
int map[16][16];
int cache[16][1<<16];
int travel(int n, int a, int dist, vector<bool>& visited){
    if(n==0) // 다 방문한 경우..........
        return dist;
    int ret=987654321;
    for(int togo=0; togo<N; ++togo){
        if(visited[togo]) continue;
        visited[togo]=true;
        int cand;
        if(map[a][togo])
            cand=travel(n-1, togo, dist+map[a][togo],visited);
        ret=min(ret, cand);
        visited[togo]=false;
    }

    return ret;
}

int travel2(int here, int visited){
    if(visited==(1<<N)-1) return map[here][0];
    int& ret=cache[here][visited];
    if(ret!=-1) return ret;
    ret=987654321;
    for(int togo=0; togo<N; ++togo){
        if(visited&(1<<togo)) continue; //방문한 경우
        int cand=map[here][togo]+travel2(togo, visited+(1<<togo));
        ret=min(ret, cand);
    }
    return ret;
}
int main() {
    cin>>N;
    for(int i=0; i<N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if(map[i][j]==0)
                map[i][j]=987654321;
        }
    }
    vector<bool> visited(N, false);
    memset(cache, -1, sizeof(cache));
    //cout<<travel(N, 0, 0, visited);
    cout<<travel2(0, 1);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}