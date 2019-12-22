#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, E;
vector<vector<int>> adj, children;
vector<int> discovered, finished, depth, subtree;
int counter = 0;

void init() {
    discovered.resize(N);
    finished.resize(N);
    subtree.resize(N);
    depth.resize(N);
}

void dfs(int here, int parent, int dep) {
    discovered[here] = subtree[here] = counter++;
    depth[here] = dep++;
    for(auto &there:adj[here]) {
        if(there==parent)
            continue;
        if(discovered[there]==-1) {
            dfs(there, here, dep+1);
            subtree[here] = min(subtree[here], subtree[there]);
            children[here].emplace_back(there);
        } else {
            subtree[here] = min(subtree[here], discovered[there]);
        }
    }
}

int is_descendant(int a, int b) {
    return discovered[b]<=discovered[a] && finished[b]>=finished[a];
}

int find_related_child(int me, int descendant) {
    int lo = 0, hi=children[me].size()-1;
    while(lo!=hi) {
        int mid = (lo+hi)/2;
        if(discovered[descendant] > fin)
    }
}

int main() {
    cin>>N>>E;
    adj.resize(N);
    for(int i=0; i<E; ++i) {
        int u, v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int Q;
    cin>>Q;
    for(int i=0; i<Q; ++i) {
        int cmd;
        cin>>cmd;
        if(cmd == 1) {
            // (G1, G2)를 제거해도 A->B로 갈 수 있는가?
            int A, B, G1, G2;
            cin>>A>>B>>G1>>G2;
            A--; B--; G1--; G2--;
            if(is_descendant(G1, G2)) swap(G1, G2);

        } else {
            // C를 제거해도 A->B로 갈 수 있는가?
            int A, B, C;
            cin>>A>>B>>C;
            A--; B--; C--;
            //1. 단절점이 아니면 상관없어
            //2. 단절점이면? A랑 B가 쪼개지는지를 봐야함

        }
    }
    return 0;
}