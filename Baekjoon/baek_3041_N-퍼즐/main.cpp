#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> board;
vector<pair<int, int>> answer;
int getDist(pair<int, int> here, pair<int, int> there){
    return abs(here.first-there.first)+abs(here.second-there.second);
}

int main() {
    board.resize(16);
    answer.resize(16);
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            char c;
            cin>>c;
            if(c=='.')
                continue;
            board[c-'A']={i, j};
        }
    }
    int index=0;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            answer[index++]={i, j};
        }
    }
    int ret=0;
    for(int i=0; i<15; ++i){
        ret+=getDist(answer[i], board[i]);
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}