#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int board[100][100], n;


int dx[]={1, -1, 0, 0}, dy[]={0,0,-1,1};

bool isRange(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

// 잘못짰다고... ㅠ _ ㅠ
bool canGo(int x, int y, int k) {
    for(int low=0; low<=200; ++low) {
        if(board[x][y]<low || board[x][y]>low+k)
            continue;
        bool visited[100][100] = {false,};
        queue<pair<int, int>> q;
        visited[x][y] = true;
        q.push({x, y});
        while (!q.empty()) {
            pair<int, int> here = q.front();
            q.pop();
            if (here.first == n - 1 && here.second == n - 1)
                return true;
            for (int i = 0; i < 4; ++i) {
                pair<int, int> there = {here.first + dx[i], here.second + dy[i]};
                if (!isRange(there.first, there.second))
                    continue;
                if (visited[there.first][there.second])
                    continue;
                if (board[there.first][there.second] < low || board[there.first][there.second] > low + k)
                    continue;
                q.push(there);
                visited[there.first][there.second] = true;
            }
        }
    }
    return false;
}

int main() {
    cin>>n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin>>board[i][j];
        }
    }
    int lo=-1, hi=200;  //lo=false , hi=true;
    while(lo+1<hi) {
        int mid=(lo+hi)/2;
        if(canGo(0, 0, mid)) {
            hi=mid;
        } else
            lo=mid;
    }
    cout<<hi;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}