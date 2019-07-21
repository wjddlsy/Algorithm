#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet{
    vector<int> parent, rank, size, member;
    DisjointSet(int n):parent(n), rank(n, 1), size(n, 1), member(n){
        for(int i=0; i<n; ++i){
            parent[i]=i;
            member[i]=i;
        }
    }

    int find(int u){
        if(u==parent[u])
            return u;
        return parent[u]=find(parent[u]);
    }

    void merge(int u, int v){
        u=find(u); v=find(v);
        if(u==v) return;
        if(size[u]>size[v]) swap(u, v);
        parent[u]=v;
        size[v]+=size[u];
        if(size[u]==size[v]) ++rank[v];

    }
};

// 펜윅트리의 구현
struct FenwickTree{
    vector<int> tree;
    FenwickTree(int n) : tree(n+1) {}
    // A[0..pos] 의 부분합을 구한다.
    int sum(int pos){
        ++pos;
        // 인덱스가 1부터 시작한다고 생각
        int ret=0;
        while(pos>0){
            ret+=tree[pos];
            // 다음 구간을 찾기 위해 최종 비트를 지움
            pos&=(pos-1);
        }
        return ret;
    }
    // A[pos]에 val을 더한다.
    void add(int pos, int val){
        ++pos;
        while(pos<tree.size()){
            tree[pos]+=val;
            pos+=(pos & -pos);
        }
    }
};

int G, P, in;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>G>>P;
    FenwickTree ft(G);
    for(int i=0; i<P; ++i){
        cin>>in;
        ft.add(in, 1);
        if(ft.sum(in)>in) {
            cout << i;
            return 0;
        }
    }

    cout<<P;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}