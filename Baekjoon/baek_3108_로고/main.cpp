#include <iostream>
#include <vector>

using namespace std;

class Rectg {
public:
    int x1, y1, x2, y2;

    Rectg() = default;

    Rectg(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {

    }

};

vector<vector<int>> adj;

bool isConnect(const Rectg *a, const Rectg *b) {
    if (a->x1<b->x1 && b->x2<a->x2 && a->y1<b->y1 && b->y2<a->y2) {
        return false;
    }
    if (a->x1>b->x1 && b->x2>a->x2 && a->y1>b->y1 && b->y2>a->y2) {
        return false;
    }
    if (b->x1>a->x2 || b->x2<a->x1 || b->y1>a->y2 || b->y2<a->y1) {
        return false;
    }
    return true;
}

vector<bool> visited;
int N;

void dfs(int here) {
    visited[here] = true;
    for(auto &there:adj[here]) {
        if(visited[there])
            continue;
        dfs(there);
    }
}

int dfsAll() {
    int cnt = 0;
    visited = vector<bool>(N+1, false);
    for(int i=0; i<=N; ++i) {
        if(visited[i])
            continue;
        dfs(i);
        cnt++;
    }
    return cnt;
}
int main() {
    cin >> N;
    vector<Rectg *> rectgs(N+1);
    rectgs[0] = new Rectg(0, 0, 0, 0);

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto *rectg = new Rectg(x1, y1, x2, y2);
        rectgs[i+1] = rectg;
    }

    adj.resize(N+1);
    // 이어져있는 직사각형들을 찾는다.
    for(int i=0; i<=N; ++i) {
        for(int j=i+1; j<=N; ++j) {
            if(isConnect(rectgs[i], rectgs[j])) {
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    cout << dfsAll() - 1;

   // std::cout << "Hello, World!" << std::endl;
    return 0;
}
