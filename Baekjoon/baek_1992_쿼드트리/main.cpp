#include <iostream>
#include <vector>

using namespace std;

vector<string> board;


int isAll(int x, int y, int n) {
    bool color = board[x][y] - '0';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (color != board[x+i][y+j]-'0')
                return -1;
        }
    }
    return color;
}

void solve(int x, int y, int n) {
    if (isAll(x, y, n) != -1) {
        cout << isAll(x, y, n);
    } else {
        cout<<'(';
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
        cout<<')';
    }
}

int main() {
    int n;
    cin >> n;
    board.resize(n);
    for (auto &row:board) {
        cin >> row;
    }
    solve(0, 0, n);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}