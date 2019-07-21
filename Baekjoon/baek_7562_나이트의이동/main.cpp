#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dir[8][2]={{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
               {1, -2}, {2, -1}, {2, 1}, {1, 2}};

bool isRange(int r, int c, int l){
    if(r<0 || r>=l || c<0 || c>=l)
        return false;
    return true;
}
int bfs(pair<int, int> start, pair<int, int> end, int l){
    queue<pair<int, int>> q;
    int discovered[300][300];
    memset(discovered, 0, sizeof(discovered));
    q.push(start);
    while(!q.empty()){
        pair<int, int> here=q.front();
        if(here==end)
            return discovered[here.first][here.second];
        q.pop();
        for(int i=0; i<8; ++i){
            pair<int, int> there={here.first+dir[i][0], here.second+dir[i][1]};
            if(isRange(there.first, there.second, l) && !discovered[there.first][there.second]){
                discovered[there.first][there.second]=discovered[here.first][here.second]+1;
                q.push(there);
            }
        }
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        pair<int, int> start, end;
        cin>>start.first>>start.second>>end.first>>end.second;
        cout<<bfs(start, end, l)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}