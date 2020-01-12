#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Shark {
    int id;
    int r, c, s, d, z;

public:
    Shark() = default;;

    Shark(int id, int r, int c, int s, int d, int z) : id(id), r(r), c(c), s(s), d(d), z(z) {

    }
};

int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
int R, C, M;
int board[100][100];
map<int, Shark> m;

int fishing(int c) {
    for (int i = 0; i < R; ++i) {
        int id = board[i][c];
        if (id) {
            board[i][c] = 0;
            return m[id].z;
        }
    }
    return 0;
}

int calculate(int n, int d, int s, int pos, Shark &shark) {
    int mod = (n - 1) * 2;
    int npos = (pos + (s * d + mod * s)) % mod;
    if (npos >= n) {
        npos = (n - 1) - (npos - (n - 1));
        shark.d % 2 == 0 ? shark.d++ : shark.d--;
    }
    return npos;
}

void move() {
    int temp[100][100] = {0};
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!board[i][j])
                continue;
            int id = board[i][j];
            Shark shark = m[id];
            shark.r = calculate(R, dr[shark.d], shark.s, shark.r, shark);
            shark.c = calculate(C, dc[shark.d], shark.s, shark.c, shark);
            m[id] = shark;
            if (temp[shark.r][shark.c]) {
                Shark o_shark = m[temp[shark.r][shark.c]];
                temp[shark.r][shark.c] = (o_shark.z > shark.z ? o_shark.id : shark.id);
            } else {
                temp[shark.r][shark.c] = id;
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            board[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> M;
    int id = 1;
    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--;
        c--;
        d--;
        Shark shark(id, r, c, s, d, z);
        board[r][c] = id;
        m[id++] = shark;
    }
    int ret = 0;
    for (int i = 0; i < C; ++i) {
        ret += fishing(i);
        move();
        //print();
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
