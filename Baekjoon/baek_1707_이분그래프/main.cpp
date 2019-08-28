#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 두가지색칠하기 문제아닌가..
// 인접한 건 같은 색깔로 못칠할 때 두 가지 색으로 할 수 있을까요 ~~
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int V, E;
        cin>>V>>E;
        vector<vector<int>> adj(V);
        for(int i=0; i<E; ++i) {
            int u, v; cin>>u>>v;
            u--; v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        bool flag=true;
        vector<int> discovered(V, 0);
        queue<int> q;
        for(int start=0; start<V; ++start) {
            if(!flag)
                break;
            if(discovered[start]!=0)
                continue;
            q.push(start);
            discovered[start] = -1;
            while (!q.empty() && flag) {
                int here = q.front();
                q.pop();
                for (auto &there:adj[here]) {
                    if (discovered[there] == 0) {
                        discovered[there] = discovered[here] * -1;
                        q.push(there);
                    } else if (discovered[here] == discovered[there]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        cout<<(flag?"YES":"NO")<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}