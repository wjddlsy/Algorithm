#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, R, C;
vector<vector<pair<int, int>>> rotations;
int blockSize;

vector<string> board;
int covered[10][10];
int best;

// block 인듯
vector<string> rotate(const vector<string>& arr){
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for(int i=0; i<arr.size(); ++i){
        for(int j=0; j<arr[0].size(); ++j){
            ret[j][arr.size()-i-1]=arr[i][j];
        }
    }
    return ret;
}

void generateRotations(vector<string> block){
    rotations.clear();
    rotations.resize(4);
    for(int rot=0; rot<4; ++rot){
        int originY=-1, originX=-1;
        for(int i=0; i<block.size(); ++i){
            for(int j=0; j<block[i].size(); ++j){
                if(block[i][j]=='#') {
                    if(originY==-1) {
                        originY=i;
                        originX=j;
                    }
                    rotations[rot].emplace_back(i-originY, j-originX);
                }
            }
        }
        block=rotate(block);
    }
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()),rotations.end());
    blockSize=rotations[0].size();
}
bool isRange(int y, int x){
    return y>=0 && y<H && x>=0 && x<W;
}
bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
    bool flag=true;
    for(auto &cell:block){
        int ny=y+cell.first, nx=x+cell.second;
        if(!isRange(ny, nx)) {
            flag=false;
            continue;
        }
        if(covered[ny][nx]!=0)
            flag=false;
        covered[ny][nx]+=delta;
    }
    return flag;
}
void search(int placed, int emptySpace) {
    if(best >= placed + emptySpace / blockSize)
        return;
    int y=-1, x=-1;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            if(covered[i][j]==0) {
                y=i;
                x=j;
                break;
            }
        }
        if(y!=-1)
            break;
    }
    // 기저사례: 게임의 모든 칸을 처리한 경우
    if(y==-1) {
        best=max(best, placed);
        return;
    }
    // 이 칸을 덮는다.
    for(int i=0; i<rotations.size(); ++i){
        if(set(y, x, rotations[i], 1))
            search(placed+1, emptySpace-blockSize);
        set(y, x, rotations[i], -1);
    }
    covered[y][x]=1;
    search(placed, emptySpace-1);
    covered[y][x]=0;
}
int solve() {
    best=0;
    int emptySpace=0;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            if(board[i][j]=='.')
                emptySpace++;
            covered[i][j]=(board[i][j]=='#'?1:0);
        }
    }
    search(0, emptySpace);
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        cin>>H>>W>>R>>C;
        board.clear();
        for(int i=0; i<H; ++i){
            string s;
            cin>>s;
            board.emplace_back(s);
        }
        vector<string> block;
        for(int i=0; i<R; ++i){
            string s;
            cin>>s;
            block.emplace_back(s);
        }
        generateRotations(block);
        cout<<solve()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}