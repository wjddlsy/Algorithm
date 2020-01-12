#include <iostream>
#include <vector>

using namespace std;

string board[50];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int ret = 1;
    for (int size = 2; size <= min(N, M); ++size) {
        for (int i = 0; i <= N - size; ++i) {
            for (int j = 0; j <= M - size; ++j) {
                if (board[i][j] == board[i + size - 1][j] &&
                board[i][j] == board[i][j + size - 1] && board[i][j] == board[i + size - 1][j + size - 1]) {
                    ret = size * size;
                }
            }
        }
    }

    cout << ret;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
