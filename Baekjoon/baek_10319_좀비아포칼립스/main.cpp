#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N=1000;
const int MAX_S=101;
const int MAX_V=MAX_N*MAX_S+2;
const int INF=987654321;

struct Edge{
    int target, capacity, flow;
    Edge* reverse;
    Edge(int target, int capacity):target(target), capacity(capacity), flow(0){

    }
    int residual(){
        return capacity-flow;
    }
    void push(int amt){
        flow+=amt;
        reverse->flow-=amt;
    }
};

vector<vector<Edge*>> adj;
void add(int u, int v, int capacity){
    Edge* uv=new Edge(v, capacity);
    Edge* vu=new Edge(u, 0);
    uv->reverse=vu;
    vu->reverse=uv;
    adj[u].emplace_back(uv);
    adj[v].emplace_back(vu);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m, place, g, s, r;
        cin>>n>>place>>g>>s>>m;
        int max_v=n*MAX_S+2;
        const int S=max_v-2;
        const int E=max_v-1;
        adj=vector<vector<Edge*>>(max_v);
        place=(place-1)*MAX_S;
        add(S, place, g);
        for(int i=0; i<m; ++i){
            int a;
            cin>>a;
            a--;
            for(int j=0; j<=s; ++j){
                int here=i*MAX_S+j;
                add(here, E, INF);
            }
        }
        cin>>r;
        for(int i=0; i<r; ++i){
            int a, b, p, d;
            cin>>a>>b>>p>>d;
            a--; b--;
            for(int j=0; j+d<=s; ++j){
                int here=a*MAX_S+j, there=b*MAX_S+j+d;
                add(here, there, p);
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<s; ++j){
                int here=i*MAX_S+j, there=here+1;
                add(here, there, INF);
            }
        }
        int total=0;
        while(true){
            //vector<int> parent(max_v, -1);
            //vector<Edge*> path(max_v, nullptr);
            int parent[MAX_V];
            fill(parent, parent+MAX_V, -1);
            Edge *path[MAX_V]={nullptr};
            queue<int> q;
            q.push(S);
            parent[S]=S;
            while(!q.empty() && parent[E]==-1){
                int here=q.front();
                q.pop();
                for(auto& edge:adj[here]){
                    int there=edge->target;
                    if(edge->residual()>0 && parent[there]==-1){
                        parent[there]=here;
                        q.push(there);
                        path[there]=edge;
                    }
                }
            }
            if(parent[E]==-1) break;
            int amount=INF;
            for(int i=E; i!=S; i=parent[i]){
                amount=min(amount, path[i]->residual());
            }
            for(int i=E; i!=S; i=parent[i]){
                path[i]->push(amount);
            }
            total+=amount;
        }
        cout<<total<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}