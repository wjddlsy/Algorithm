#include <iostream>

using namespace std;

const int dx[8]={-1,-1,-1,1,1,1,0,0};
const int dy[8]={-1,0, 1, -1, 0, 1, -1, 1};

string board[5];



bool inRange(int y, int x){
    if(y>=0 && y<5 && x>=0 && x<5)
        return true;
    return false;
}


bool hasWord(int y, int x, const string& word){
    if(!inRange(y,x)) return false;
    if(board[y][x]!=word[0]) return false;
    if(word.size()==1) return true;

    for(int dir=0; dir<8; ++dir){
        int nextY=y+dy[dir], nextX=x+dx[dir];
        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        for(int i=0; i<5; ++i){
            cin >> board[i];
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}