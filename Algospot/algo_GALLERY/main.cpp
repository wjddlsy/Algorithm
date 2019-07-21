#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


vector<vector<int>> adj;
vector<bool> visited;
const int UNWATCHED=0;
const int WATCHED=1;
const int INSTALLED=2;

int installed;
int dfs(int here){
    visited[here]=true;
    int children[3]={0,0,0};
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
        if(!visited[there]){
            ++children[dfs(there)];
        }
    }
    if(children[UNWATCHED]){
        ++installed;
        return INSTALLED;
    }
    if(children[INSTALLED])
        return WATCHED;
    return UNWATCHED;
}

int main() {
    int C;
    cin>>C;
    while(C--){
        int G, H;
        cin>>G>>H;
        adj=vector<vector<int>>(G+1);
        visited=vector<bool>(G+1, false);
        for(int i=0; i<H; ++i){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        installed=0;
        for(int i=0; i<G; ++i){
            if(!visited[i]&&dfs(i)==UNWATCHED)
                installed++;
        }
        cout<<installed<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}