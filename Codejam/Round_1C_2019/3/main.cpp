#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> board;
bool whoWin;
int becca;
int R, C;

bool isRange(int r, int c){
    return r>=0&&r<R&&c>=0&&c<C;
}

bool spread(vector<vector<char>>& cell, int dir, int r, int c){
    if(dir==0){
        int rr=r;
        while(isRange(rr, c)){
            if(cell[rr][c]=='#')
                return false;
            rr++;
        }
        while(isRange(rr, c)){
            if(cell[rr][c]=='#')
                return false;
            rr--;
        }
    }
    else {
        int cc=c;
        while(isRange(r, cc)){
            if(cell[r][cc]=='#')
                return false;

            c++;
        }
        while(isRange(r, cc)){
            if(cell[r][cc]=='#'){
                return false;
            }
            cc--;
        }
    }
    return true;
}

void draw(vector<vector<char>>& cell, int dir, int r, int c){
    cell[r][c]='?';
    if(dir==0){
        int rr=r;
        while(isRange(rr, c)){
            if(cell[rr][c]=='.') {
                cell[rr][c]='?';
            }

            rr++;
        }
        while(isRange(rr, c)){
            if(cell[rr][c]=='.')
                cell[rr][c]='?';
            else
                break;
            rr--;
        }
    }
    else {
        int cc=c;
        while(isRange(r, cc)){
            if(cell[r][cc]=='.')
                cell[r][cc]='?';
            else
                break;
            c++;
        }
        while(isRange(r, cc)){
            if(cell[r][cc]=='.'){
                cell[r][cc]='?';
            }

            cc--;
        }
    }
}

bool go(vector<vector<char>>& cell, bool turn, int num){
    auto origin=cell;
    turn=turn^1;
    int cnt=0;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            if(cell[i][j]!='.')
                continue;
            if(spread(cell, 0, i, j)){
                draw(cell, 0, i, j);
                go(cell, turn, num+1);
                cnt++;
                cell=origin;
            }
            if(spread(cell, 1, i, j)){
                draw(cell, 1, i, j);
                go(cell, turn, num+1);
                cnt++;
                cell=origin;
            }
        }
    }
    if(num==0){
        cnt++;
    }
    if(cnt==0) {
        return turn;
    }
}
int main() {
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        cin>>R>>C;
        board=vector<vector<char>>(R, vector<char>(C));
        whoWin=0;
        becca=0;
        int num=R*C;
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                cin>>board[i][j];
                if(board[i][j]=='#'){
                    num--;
                }
            }
        }
        go(board, 0, 0);
        if(whoWin==false){
            cout<<becca;
        }
        else
            cout<<0;
        cout<<'\n';

    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}