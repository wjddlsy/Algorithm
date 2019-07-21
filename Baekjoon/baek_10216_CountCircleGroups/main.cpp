#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int dist(int x, int y, int nx, int ny){
    return (x-nx)*(x-nx)+(y-ny)*(y-ny);
}

void dfs(int here){
    if(visited[here])
        return;
    visited[here]=true;
    for(int i=0; i<adj[here].size(); ++i){
        dfs(adj[here][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        vector<tuple<int, int, int>> info;
        adj = vector<vector<int>>(N);
        visited = vector<bool>(N, false);

        for (int i = 0; i < N; ++i) {
            int x, y, R;
            cin >> x >> y >> R;
            info.push_back(make_tuple(x, y, R));
        }

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int x, y, r, nx, ny, nr;
                tie(x, y, r) = info[i];
                tie(nx, ny, nr) = info[j];
                int d = dist(x, y, nx, ny);
                if ((r + nr) * (r + nr) >= d) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                dfs(i);
                ret++;
            }
        }

        cout << ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}