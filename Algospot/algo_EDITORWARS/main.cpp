#include <iostream>
#include <vector>
using namespace std;

struct BipartiteUnionFind {
    vector<int> parent, rank, size, enemy;
    BipartiteUnionFind(int n): parent(n), rank(n,1), size(n,1), enemy(n, -1){
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
    }
    int find(int u) {
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }

    //merge 후 부모 반환
    int merge(int u, int v){
        if(u==-1 || v==-1) return max(u, v);
        u=find(u); v=find(v);
        if(u==v) return u;
        if(rank[u]>rank[v]) swap(u, v);
        if(rank[u]==rank[v]) rank[v]++;
        parent[u]=v;
        size[v]+=size[u];
        return v;
    }
    bool dis(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return false;
        int a=merge(u, enemy[v]), b=merge(v, enemy[u]);
        enemy[a]=b; enemy[b]=a;
        return true;
    }
    bool ack(int u, int v){
        u=find(u); v=find(v);
        if(enemy[u]==v) return false;
        int a=merge(u, v), b=merge(enemy[u], enemy[v]);
        enemy[a]=b;
        if(b!=-1) enemy[b]=a;
        return true;
    }
};

int maxParty(const BipartiteUnionFind& buf, int n){
    int ret=0;
    for(int node=0; node<n; ++node){
        // 루트만 신경씀
        if(buf.parent[node]==node){
            int enemy=buf.enemy[node];
            if(enemy>node) continue;
            int mySize=buf.size[node];
            int enemySize=(enemy==-1?0:buf.size[enemy]);
            ret+=max(mySize, enemySize);
        }
    }
    return ret;
}
int main() {
    int C;
    cin>>C;
    while(C--){
        int N, M;
        bool flag=true;
        cin>>N>>M;
        BipartiteUnionFind bp(N);
        for(int i=0; i<M; ++i){
            string s;
            int a, b;
            cin>>s>>a>>b;
            if(!flag)
                continue;
            if(s=="ACK"){
                if(!bp.ack(a, b)){
                    cout<<"CONTRADICTION AT "<<i+1<<'\n';
                    flag=false;
                }
            }
            else if(s=="DIS"){
                if(!bp.dis(a, b)){
                    cout<<"CONTRADICTION AT "<<i+1<<'\n';
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<"MAX PARTY SIZE IS "<<maxParty(bp, N)<<endl;
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}