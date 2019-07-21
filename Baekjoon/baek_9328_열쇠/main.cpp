#include <iostream>
#include <queue>
using namespace std;


int h, w, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

bool isRange(int x, int y){
    return x>=0 && x<=h+1 && y>=0 && y<=w+1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        char board[102][102]={};

        cin >> h >> w;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                    cin >> board[i][j];
            }
        }
        string s; cin>>s;
        bool hasKey[26]={};
        for(char &c:s) {
            hasKey[c-'a']=true;
        }


        int ret = 0;
        queue<pair<int, int>> q;
        queue<pair<int, int>> wait[26];
        bool discovered[102][102]={};
        q.push({0, 0});

        discovered[0][0] = true;
        while (!q.empty()) {

            pair<int, int> here = q.front();
            q.pop();

            if (board[here.first][here.second] == '$')
                ret++;
            for (int i = 0; i < 4; ++i) {
                pair<int, int> there = {here.first + dx[i], here.second + dy[i]};
                if (!isRange(there.first, there.second))
                    continue;
                char cost=board[there.first][there.second];
                if (discovered[there.first][there.second])
                    continue;
                if (cost == '*')
                    continue;
                if (cost>='A' && cost<='Z' && !hasKey[cost-'A']){
                    wait[cost-'A'].push(there);
                    continue;
                }
                if (cost>='a' && cost<='z') {
                    hasKey[cost-'a']=true;
                    while(!wait[cost-'a'].empty()) {
                        q.push({wait[cost-'a'].front().first, wait[cost-'a'].front().second});
                        wait[cost-'a'].pop();
                    }
                }
                q.push(there);
                discovered[there.first][there.second] = true;
            }
        }
        cout << ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}