#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_V 5000

int K, N;

struct Edge{
    int target, capacity, flow;
    Edge* reverse;

    Edge(int target, int capacity): target(target), capacity(capacity){
        flow=0;
        reverse=nullptr;
    }
    int residualCapacity() const {
        return capacity-flow;
    }

    void push(int amt){
        flow+=amt;
        reverse->flow-=amt;
    }
};




vector<vector<Edge*>> adj;

void addEdge(int u, int v, int capacity){
    Edge* uv=new Edge(v, capacity), *vu=new Edge(u, 0);
    uv->reverse=vu;
    vu->reverse=uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);

}
int main() {
    int t=1;
    while(true){
        cin>>K>>N;
        if(K==0 && N==0)
            return 0;
        adj=vector<vector<Edge*>>(2*N);
        cout<<"Case "<<t<<":\n";
        for(int i=0; i<N; ++i){
            addEdge(2*i, 2*i+1, 1);
            while(true){
                char delimiter;
                int a;
                scanf("%d%c", &a, &delimiter);
                a--;
                addEdge(i*2+1, a*2, 1);
                if(delimiter=='\n') break;
            }
        }

        bool flag=false;
        int S=1, E=2;
        for(int j=0; j<K; ++j){
            vector<int> parent(2*MAX_V, -1);
            Edge* path[2*MAX_V];
            parent[S]=S;
            queue<int> q;
            q.push(S);
            while(!q.empty() && parent[E]==-1){
                int here=q.front(); q.pop();
                for(auto& edge:adj[here]){
                    int there=edge->target;
                    if(parent[there]==-1 && edge->residualCapacity()>0){
                        parent[there]=here;
                        q.push(there);
                        path[there]=edge;
                    }
                }
            }
            if(parent[E]==-1){
                flag=true;
                break;
            }
            for(int p=E; p!=S; p=parent[p]){
                path[p]->push(1);
            }
        }
        if(flag) cout<<"Impossible"<<'\n';
        else {
            for(int j=0; j<K; ++j){
                int prev=-2, curr=S;
                while(curr!=E){
                    if(prev/2!=curr/2) cout<<curr/2+1<<' ';
                    prev=curr;
                    for(auto& edge:adj[curr]){
                        int next=edge->target;
                        if(edge->flow==1){
                            edge->flow=0;
                            curr=next;
                            break;
                        }
                    }
                }
                cout<<E/2+1<<'\n';
            }
        }
        cout<<'\n';
        t++;
    }
    return 0;
}