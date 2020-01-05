#include <iostream>

using namespace std;

char board[50][50];
int N;

int maxCandy() {
    int ret = 1;
    for(int i=0; i<N; ++i) {
        int cnt = 1;
        for(int j=1; j<N; ++j) {
            if(board[i][j] == board[i][j-1]) {
                cnt++;
            } else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }

    for(int i=0; i<N; ++i) {
        int cnt = 1;
        for(int j=1; j<N; ++j) {
            if(board[j][i] == board[j-1][i]) {
                cnt++;
            } else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }

    return ret;
}
int swaping() {
    int ret = maxCandy();
    for(int i=0; i<N; ++i) {
        for(int j=1; j<N; ++j) {
            swap(board[i][j], board[i][j-1]);
            ret = max(ret, maxCandy());
            swap(board[i][j], board[i][j-1]);

            swap(board[j][i], board[j-1][i]);
            ret = max(ret, maxCandy());
            swap(board[j][i], board[j-1][i]);
        }
    }
    return ret;
}

int main() {
    cin >> N;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> board[i][j];
        }
    }

    cout << swaping();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
