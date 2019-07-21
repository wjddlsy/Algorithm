//#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct OptimizedDisjointSet{
    vector<int> parent, rank;
    OptimizedDisjointSet(int n):parent(n), rank(n,1){
        for(int i=0; i<n; ++i)
            parent[i]=i;

    }

    int find(int u) {
        if(u==parent[u]) return  u;
        parent[u]=find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return;
        if(rank[u]<rank[v]) swap(u,v);
        if(rank[u]==rank[v]) ++rank[v];

        parent[u]=v;

    }
};

struct NaiveDisjointSet{
    vector<int> parent;
    NaiveDisjointSet(int n):parent(n){
        for(int i=0; i<n; ++i)
            parent[i]=i;
    }

    int find(int u) const{
        if(u==parent[u]) return  u;
        return find(parent[u]);
    }

    void merge(int u, int v){
        u=find(u); v=find(v);

        if(u==v) return;
        parent[u]=v;
    }
};
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m;
    scanf("%d %d", &n, &m);
    //cin>>n>>m;
    OptimizedDisjointSet s(n+1);
    while(m--){
        int cmd,a,b;
        scanf("%d %d %d", &cmd, &a, &b);
        //cin>>cmd>>a>>b;
        if(!cmd){
            s.merge(a,b);
        }
        else{
            if(s.find(a)==s.find(b))
                printf("YES \n");
                //cout<<"YES"<<'\n';
            else
                printf("NO \n");
                //cout<<"NO"<<'\n';
        }

    }
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}