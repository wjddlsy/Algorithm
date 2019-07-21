#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct DisjointSet{
    vector<int> parent, rank, size;
    DisjointSet(int n) : parent(n), rank(n, 1), size(n,1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u]==u)
            return u;
        return parent[u]=find(parent[u]);
    }
    int getSize(int u){
        u=find(u);
        return size[u];
    }
    void merge(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return;
        if(rank[u]>rank[v]) swap(u, v);
        parent[u]=v;
        int tmp=size[u]+size[v];
        size[u]=tmp; size[v]=tmp;
        if(rank[u]==rank[v]) ++rank[v];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int F;
        cin>>F;
        unordered_map<string, int> m;
        DisjointSet ds(10000);
        int index=0;
        for(int i=0; i<F; ++i){
            string a, b;
            cin>>a>>b;
            auto it_a=m.find(a); auto it_b=m.find(b);
            if(it_a==m.end()){
                m[a]=index++;
            }
            if(it_b==m.end()){
                m[b]=index++;
            }
            ds.merge(m[a], m[b]);
            cout<<ds.getSize(m[a])<<'\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}