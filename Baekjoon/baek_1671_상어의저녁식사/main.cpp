#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int N;
int adj[50][50];
int aMatch[50], bMatch[50];
bool visited[50];
bool dfs(int a){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=0; b<N; ++b){
        if(!adj[a][b])
            continue;
        if( bMatch[b]==-1 || dfs(bMatch[b])){
            aMatch[a]=b;
            bMatch[b]=a;
            return true;
        }
    }
    return false;
}
int bipartiteMatch(){
    int ret=0;
    for(int i=0; i<N; ++i){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ret++;
    }
    return ret;
}
int main() {
    cin>>N;
    vector<tuple<int, int, int>> sharks;
    for(int i=0; i<N; ++i){
        int size, speed, intel;
        cin>>size>>speed>>intel;
        sharks.emplace_back(size, speed, intel);
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(i==j)
                continue;
            if(sharks[i]==sharks[j] && i>j)
                continue;
            if(get<0>(sharks[i])>=get<0>(sharks[j]) && get<1>(sharks[i])>=get<1>(sharks[j]) &&
                    get<2>(sharks[i])>=get<2>(sharks[j]))
                adj[i][j]=1;
        }
    }

    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int ret=0;
    ret+=bipartiteMatch();
    ret+=bipartiteMatch();
    cout<<N-ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}