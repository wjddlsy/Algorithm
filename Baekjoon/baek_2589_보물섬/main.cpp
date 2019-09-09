#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string board[50];
int l, w;
int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};

bool isRange(pair<int, int> p) {
    return p.first>=0 && p.first<l && p.second>=0 && p.second<w;
}
int main() {
    cin>>l>>w;
    vector<pair<int, int>> lands;
    for(int i=0; i<l; ++i) {
        cin>>board[i];
    }
    for(int i=0; i<l; ++i) {
        for(int j=0; j<w; ++j) {
            if(board[i][j]=='L')
                lands.emplace_back(i, j);
        }
    }
    int ret = 0;
    for(auto &land:lands) {
        queue<pair<int, int>> q;
        vector<vector<int>> discovered(l, vector<int>(w, -1));
        q.push(land);
        discovered[land.first][land.second] = 0;
        while(!q.empty()) {
            pair<int, int> here = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                pair<int, int> there={here.first+dx[i], here.second+dy[i]};
                if(!isRange(there))
                    continue;
                if(discovered[there.first][there.second]!=-1)
                    continue;
                if(board[there.first][there.second]=='W')
                    continue;
                discovered[there.first][there.second] = discovered[here.first][here.second] + 1;
                q.push(there);
                ret = max(ret, discovered[there.first][there.second]);
            }
        }
    }

    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}