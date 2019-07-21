#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Edge{
    int target, capacity, flow;
    Edge* reverse;

    Edge(int target, int capacity): target(target), capacity(capacity){
        flow=0;
        reverse=nullptr;
    }
    int residual() const {
        return capacity-flow;
    }

    void push(int amt){
        flow+=amt;
        reverse->flow-=amt;
    }
};

vector<vector<Edge*>> adj;
int n, m;
const int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
const int INF=987654321;

void add(int u, int v, int capacity){
    Edge* uv=new Edge(v, capacity), *vu=new Edge(u, 0);
    uv->reverse=vu;
    vu->reverse=uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);

}

bool isRange(int x, int y){
    return x>=0&&x<n&&y>=0&&y<m;
}

int networkFlow(int src, int sink){
    int ret=0;

    while(true) {
        queue<int> q;
        vector<int> parent(n * m + 2, -1);
        vector<Edge*> path(n*m+2);
        q.push(src);
        parent[src] = src;

        int amount=INF;
        while (!q.empty() && parent[sink] == -1) {
            int here=q.front(); q.pop();
            for(auto& edge:adj[here]){
                int there=edge->target;
                if(parent[there]==-1 && edge->residual()>0){
                    parent[there]=here;
                    q.push(there);
                    path[there]=edge;
                    amount=min(amount, edge->residual());
                }
            }
        }
        if(parent[sink]==-1){
            break;
        }
//        int amount=INF;
//
//        for(int p=sink; p!=src; p=parent[p]){
//            amount=min(amount, path[p]->residual());
//        }


        for(int p=sink; p!=src; p=parent[p]){
            path[p]->push(amount);
        }
        ret+=amount;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;

        int S=n*m, E=n+m+1;

        adj.clear();
        adj.resize(n*m+2);

        int board[50][50];
        bool check[50][50]={0};
        int total=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>board[i][j];
                total+=board[i][j];
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; j++){
                int blue=i*n+j;
                if(i%2==j%2) {
                    add(S, blue, board[i][j]);
                    for (int dir = 0; dir < 4; ++dir) {
                        int x = i + dx[dir], y = j + dy[dir];
                        if (!isRange(x, y))
                            continue;
                        int red = x * n + y;
                        add(blue, red, INF);
                    }
                }
                else {
                    add(blue, E, board[i][j]);
                }
            }
        }
        cout<<total-networkFlow(S, E)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}