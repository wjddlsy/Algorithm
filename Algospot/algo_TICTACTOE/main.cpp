#include <iostream>
#include <vector>

using namespace std;

bool isFinished(const vector<string>& board, char turn){
     //가로줄 검사
     for(int i=0; i<3; ++i){
         if(board[i][0]==turn && board[i][1]==turn && board[i][2]==turn)
             return true;
     }
     //세로줄 검사
     for(int i=0; i<3; ++i){
         if(board[0][i]==turn && board[1][i]==turn && board[2][i]==turn)
             return true;
     }
     //대각선 검사
     if(board[0][0]==turn && board[1][1]==turn && board[2][2]==turn)
         return true;
     if(board[2][0]==turn && board[1][1]==turn && board[0][2]==turn)
         return true;
     return false;
}

int bijection(const vector<string>& board){
    int ret=0;
    for(int y=0; y<3; ++y){
        for(int x=0; x<3; ++x){
            ret=ret*3;
            if(board[y][x]=='o') ++ret;
            else if(board[y][x]=='x') ret+=2;
        }
    }
    return ret;
}
//-2로 초기화
int cache[19683];
int canWin(vector<string>& board, char turn){
    if(isFinished(board, 'o'+'x'-turn)) return -1;
    int& ret = cache[bijection(board)];
    if(ret!=-2) return ret;
    int minValue=2;
    for(int y=0; y<3; ++y){
        for(int x=0; x<3; ++x){
            if(board[y][x]=='.'){
                board[y][x]=turn;
                minValue=min(minValue, canWin(board,'o'+'x'-turn));
                board[y][x]='.';
            }
        }
    }
    if(minValue==2||minValue==0) return ret=0;
    return ret = -minValue;
}

int main() {
    int c;
    cin>>c;
    for(int i=0; i<19683; ++i){
        cache[i]=-2;
    }
    while(c--){
        vector<string> board;
        int num=0;
        for(int i=0; i<3; ++i){
            string ss;
            cin>>ss;
            for(int j=0; j<3; ++j){
                if(ss[j]!='.')
                    num++;
            }
            board.push_back(ss);
        }
        char s='x';
        if(num%2==1)
            s='o';
        int ret=canWin(board, s);
        if(ret==0)
            cout<<"TIE"<<endl;
        else if(ret==1)
            cout<<s<<endl;
        else if(ret==-1)
            cout << (char)('o' + 'x' - s) << endl;
        //cout<<canWin(board, 'x')<<endl;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}