#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};

bool isRange(pair<int, int> rc){
    return rc.first>=0 && rc.first<3 && rc.second>=0 && rc.second<3;
}

bool isEqual(vector<vector<int>>& start, vector<vector<int>>& end){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(start[i][j]!=end[i][j])
                return false;
        }
    }
    return true;
}

int main() {

    vector<vector<int>> start(3, vector<int>(3, 0)), end(3, vector<int>(3, 0));
    pair<int, int> zero;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cin>>start[i][j];
            if(start[i][j]==0) {
                zero={i, j};
            }
        }
    }
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            end[i][j]=i*3+j+1;
            if(end[i][j]==9)
                end[i][j]=0;
        }
    }
    queue<vector<vector<int>>> q;
    queue<pair<int, int>> zeroQ;
    map<vector<vector<int>>, int> discovered;
    q.push(start);
    zeroQ.push(zero);
    discovered[start]=0;
    while(!q.empty()){
        vector<vector<int>> here=q.front();
        pair<int, int> zh=zeroQ.front();
        q.pop();
        zeroQ.pop();

        if(isEqual(here, end))
            break;
        for(int i=0; i<4; ++i){
            pair<int, int> zt={zh.first+dx[i], zh.second+dy[i]};
            vector<vector<int>> there=here;
            if(!isRange(zt))
                continue;
            swap(there[zh.first][zh.second], there[zt.first][zt.second]);
            if(discovered.find(there)!=discovered.end())
                continue;
            q.push(there);
            zeroQ.push(zt);
            discovered[there]=discovered[here]+1;
        }
    }
    if(discovered[end]==0)
        cout<<-1;
    else
        cout<<discovered[end];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}