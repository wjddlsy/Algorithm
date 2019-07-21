#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstring>
using namespace std;

vector<int> moves; //블록의 모든 조합에 대해 차지하는 비트들의 집합
inline int cell(int y, int x){
    return 1 << (y*5+x); // 켜져있는 비트로 놓여있는지 확인

}

// 모든 블록의 조합을 생성
void precalc(){
    moves.clear();
    // 세칸짜리
    for(int y=0; y<4; ++y){
        for(int x=0; x<4; ++x){
            vector<int> cells;
            for(int dy=0; dy<2; ++dy){
                for(int dx=0; dx<2; ++dx){
                    cells.push_back(cell(y+dy, x+dx));
                }
            }
            int square = cells[0]+cells[1]+cells[2]+cells[3];
            for (int i=0; i<4; ++i)
                moves.push_back(square - cells[i]);
        }
    }

    //두칸짜리
    for (int i=0; i<5; ++i){
        for (int j=0; j<4; ++j){
            moves.push_back(cell(i,j)+cell(i, j+1));
            moves.push_back(cell(j,i)+cell(j+1,i));
        }
    }
}

char cache[1<<25];
// 현재 게임판 상태가 board일 때, 현재 차례인 사람 승리 여부
char play(int board){
    //메모이제이션
    char& ret = cache[board];
    if(ret!=-1) return ret;
    ret = 0;
    //모든 수 고려
    for (int i=0; i<moves.size(); ++i){
        // 이 수를 게임판에 놓을 수 있는가 확인
        if((moves[i]&board)==0){
            if(!play(board|moves[i])){
                ret = 1;
                break;
            }
        }
    }

    return ret;
}
int main(int argc, const char * argv[]) {
    int c, board=0;
    char a;
    cin >> c;
    precalc();
    while(c--){
        board=0;
        memset(cache, -1, sizeof(cache));
        for(int i=0; i<5; ++i){
            for(int j=0; j<5; ++j){
                cin >> a;
                if(a=='#')
                    board|=cell(i,j);
            }
        }

        if(play(board)==1)
            cout << "WINNING" << endl;
        else
            cout << "LOSING" << endl;
    }

}