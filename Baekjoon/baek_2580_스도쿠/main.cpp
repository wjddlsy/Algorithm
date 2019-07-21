#include <iostream>
#include <vector>

using namespace std;

int R[9], C[9], RC[9];
vector<pair<int, int>> empty;
vector<vector<int>> ret;
bool found= false;

void solve(vector<vector<int>>& board, int here) {
    if(found)
        return;
    if(here==empty.size()) {
        found=true;
        ret=board;
        return;
    }
    int r=empty[here].first, c=empty[here].second;
    int cand= (R[r] | C[c] | RC[(r/3)*3+c/3]);
    for(int i=1; i<=9; ++i) {
        if(!(cand & (1<<i))) {
            R[r] |= (1<<i);
            C[c] |= (1<<i);
            RC[(r/3)*3+c/3] |= (1<<i);
            board[r][c]=i;
            solve(board, here+1);
            R[r] &= ~(1<<i);
            C[c] &= ~(1<<i);
            RC[(r/3)*3+c/3] &= ~(1<<i);
            board[r][c]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> board(9, vector<int>(9, 0));
    ret=vector<vector<int>>(9, vector<int>(9, 0));
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cin>>board[i][j];
            if(board[i][j]==0)
                empty.emplace_back(i, j);
        }
    }

    int init_i=0, init_j=-3;

    for(int i=0; i<9; ++i){
        init_i=(i/3)*3; init_j=(init_j+3)%9;
        for(int j=0; j<3; ++j){
            for(int k=0; k<3; ++k) {
                int r=init_i+j, c=init_j+k;
                R[r]|=(1<<board[r][c]);
                C[c]|=(1<<board[r][c]);
                RC[i]|=(1<<board[r][c]);
            }
        }
    }
    solve(board, 0);
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout<<ret[i][j]<<" ";
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}