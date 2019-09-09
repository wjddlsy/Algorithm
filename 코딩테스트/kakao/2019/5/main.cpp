#include <vector>
#include <iostream>
using namespace std;

// 규칙
// 기둥은 바닥위 또는 보의 한쪽 끝 위 또는

bool isFrame(vector<vector<vector<int>>>& board) {
    for(int y=0; y<board.size(); ++y) {
        for(int x=0; x<board.size(); ++x) {
            if(board[y][x][0]) {
                if(y == 0 )
                    continue;
                if(board[y-1][x][0])
                    continue;
                if(x!=0 && board[y][x-1][1])
                    continue;
                if(board[y][x][1])
                    continue;
                return false;
            }
            if (board[y][x][1]) {
                if(y!=0 && board[y-1][x][0])
                    continue;
                if(y!=0 && x<board.size() && board[y-1][x+1][0])
                    continue;
                if(x!=0 && x<board.size() && board[y][x-1][1] && board[y][x+1][1])
                    continue;
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<vector<vector<int>>> board = vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

    for(auto &oper:build_frame) {
        int x = oper[0], y=oper[1], a = oper[2], b=oper[3];
        int origin = board[y][x][a];
        board[y][x][a] = b;
        if(!isFrame(board)) {
            board[y][x][a] = origin;
        }
    }

    for(int x=0; x<board.size(); ++x) {
        for(int y=0; y<board.size(); ++y) {
            vector<int> tmp;
            if(board[y][x][0]==1) {
                tmp.push_back(x);
                tmp.push_back(y);
                tmp.push_back(0);
                answer.emplace_back(tmp);
            }
            tmp.clear();
            if(board[y][x][1]) {
                tmp.push_back(x);
                tmp.push_back(y);
                tmp.push_back(1);
                answer.emplace_back(tmp);
            }
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> frames(m);
    for(int i=0; i<m; ++i) {
        for(int j=0; j<4; ++j) {
            int in; cin>>in;
            frames[i].emplace_back(in);
        }
    }
    vector<vector<int>> ret = solution(n, frames);
    for(auto &r:ret) {
        for(auto rr:r) {
            cout<<rr<<" ";
        }
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}