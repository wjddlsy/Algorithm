#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

int ret[100001];
vector<vector<int>> adjacent;

void bfs(int N, int start){
    vector<bool> visited(static_cast<unsigned long>(N+1), false);
    queue<int> q; //방문할 정점 목록
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int here=q.front();
        q.pop();
        for(int i=0; i<adjacent[here].size(); ++i){
            int there=adjacent[here][i];
            if(!visited[there]){
                q.push(there);
                visited[there]=true;
                ret[there]=here;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int N, node1, node2;
    cin>>N;
    adjacent=vector<vector<int>>(N+1);
    for(int i=0; i<N-1; ++i){
        cin>>node1>>node2;
        adjacent[node1].push_back(node2);
        adjacent[node2].push_back(node1);
    }
    bfs(N, 1);
    for(int i=2; i<=N; ++i){
        cout<<ret[i]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}