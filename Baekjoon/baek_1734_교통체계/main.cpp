#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 100001

int n, e;

vector<int> adj[MAX], children[MAX];
int finished[MAX], discovered[MAX], depth[MAX], subtree[MAX], counter=0;

// subtree[here] = here의 서브트리에서 역방향 간선으로 갈 수 있는 정점 중 가장 일찍 발견된 정점의 발견 시점
void dfs(int here, int parent, int dep){
    discovered[here]=subtree[here]=counter++;
    depth[here]=dep;
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
        if(there==parent) continue;
        if(discovered[there]==-1){
            dfs(there, here, dep+1);

            subtree[here]=min(subtree[here], subtree[there]);
            children[here].push_back(there);
        }
        else //
            subtree[here]=min(subtree[here], discovered[there]);
    }
    finished[here]=counter++;
}


int is_descendant(int a, int b){
    return discovered[b]<=discovered[a] && finished[b]>=finished[a];
}


int find_related_child(int me, int descendant){
    int lo=0, hi=children[me].size()-1;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(discovered[descendant]>finished[children[me][mid]]) lo=mid+1;
        else if(finished[descendant]<discovered[children[me][mid]]) hi=mid-1;
        else lo=hi=mid;
    }
    return children[me][lo];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>e;
    for(int i=0; i<e; ++i){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(discovered, -1, sizeof(discovered));
    dfs(0, -1, 0);
    int Q;
    cin>>Q;
    for(int i=0; i<Q; ++i){
        int type, a, b, c, d;
        cin>>type>>a>>b>>c;
        a--;b--;c--;
        if(type==1){
            cin>>d;
            d--;
            if(is_descendant(c, d)) swap(c, d); // c가 조상

            if(depth[d]!=depth[c]+1) cout<<"yes"<<'\n';
            else if(subtree[d]<discovered[d]) cout<<"yes"<<'\n';
            else if(is_descendant(a, d)==is_descendant(b, d)) cout<<"yes"<<'\n';
            else cout<<"no"<<'\n';
        } else {
            if(!is_descendant(a, c) && !is_descendant(b, c)) cout<<"yes"<<'\n';
            else if(is_descendant(a, c) && is_descendant(b, c)){
                int e=find_related_child(c, a);
                int f=find_related_child(c, b);
                if(e==f) cout<<"yes"<<'\n';
                else if(subtree[e]<discovered[c]&&subtree[f]<discovered[c]) cout<<"yes"<<'\n';
                else cout<<"no"<<'\n';

            } else {
                if(is_descendant(a, c)) swap(a, b);
                int e=find_related_child(c, b);
                if(subtree[e]<discovered[c]) cout<<"yes"<<'\n';
                else cout<<"no"<<'\n';
            }
        }

    }
    return 0;
}