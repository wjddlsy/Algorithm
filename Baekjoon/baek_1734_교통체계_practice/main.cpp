#include <iostream>
#include <vector>

using namespace std;
#define MAX_V 100000
vector<int> adj[MAX_V], children[MAX_V];
int discovered[MAX_V], finished[MAX_V], depth[MAX_V], subtree[MAX_V];
int counter=0;

int dfs(int here, int parent, int dep){
    discovered[here]=subtree[here]=counter++;
    depth[here]=dep;
    for(auto &there:adj[here]){
        
    }
}
int main() {
    int N, E;
    cin>>N>>E;
    for(int i=0; i<E; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}