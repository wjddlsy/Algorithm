#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 100
int N;
int map[MAX][MAX];
long long cache[MAX][MAX];
bool isRange(int x, int y){
    if(x<0 || x>=MAX || y<0 || y>=MAX)
        return false;
    return true;
}

long long dfs(int x, int y){
    if(!isRange(x, y))
        return 0;
    if(x==N-1 && y==N-1)
        return 1;
    long long &ret=cache[y][x];
    if(ret!=-1)
        return ret;
    ret=0;
    ret+=dfs(x+map[y][x], y)+dfs(x, y+map[y][x]);

    return ret;
}
int main() {
    cin>>N;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j)
            cin>>map[i][j];
    }
    cout<<dfs(0, 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}