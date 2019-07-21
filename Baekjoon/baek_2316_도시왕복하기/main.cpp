#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, P;

int capacity[800][800], flow[800][800];

int networkFlow(int source, int sink){
    memset(flow, 0, sizeof(flow));
    //memset(capacity, 1, sizeof(capacity));
    int totalFlow=0;
    while(true) {
        vector<int> parent(N, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            for (int there = 0; there < N; ++there) {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }

        }
        if (parent[sink] == -1) break;
        int amount = 987654321;
        for (int p = sink; p != source; p = parent[p]) {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }
        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow+=amount;
    }
    return totalFlow;

}
int main() {
    cin>>N>>P;
    for(int i=0; i<N; ++i){
        int u=i*2, v=i*2+1;
        capacity[u][v]=1;
        //capacity[v][u]=1;
    }
    N=N*2;
    for(int i =0; i<P; ++i){
        int a, b;
        cin>>a>>b;
        a--; b--;
        capacity[a*2+1][b*2]=capacity[b*2+1][a*2]=1;

        //capacity[a*2][a*2+1]=capacity[a*2+1][a*2]=1;
        //capacity[b*2][b*2+1]=capacity[b*2+1][b*2]=1;
    }
    cout<<networkFlow(1,2);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}