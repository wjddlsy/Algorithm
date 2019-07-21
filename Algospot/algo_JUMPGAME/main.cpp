#include <iostream>
#include <string.h>
using namespace std;

int board[100][100];
int cache[100][100];

int go(const int& n, int y, int x){
    //기저사례
    if(y>=n || x>=n) return 0;
    if(y==n-1 && x==n-1) return 1;

    int& ret=cache[y][x];
    if(ret!=-1) return ret;

    int s=board[y][x];
    return ret=(go(n, y+s, x) || go(n, y, x+s)); // 아래 또는 ㅗㅇ른쪽

}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cin>>board[i][j];
        }

        cout << (go(n, 0, 0)?"YES":"NO") << endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}