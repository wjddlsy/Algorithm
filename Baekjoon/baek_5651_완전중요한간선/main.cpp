#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_V 300

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int N, M;

int networkFlow(){
    memset(flow, 0, sizeof(flow));
    while(true){
        queue<int> q;
        vector<int> parent(N, -1);
        q.push(0);
        parent[0]=0;
        while(!q.empty() && parent[N-1]==-1){
            int here=q.front();
            q.pop();
            for(int there=0; there<N; ++there){
                if(parent[there]==-1 && capacity[there]-flow[there]>0){
                    q.push(there);
                    parent[there]=here;

                }
            }
        }
        // 증가경로 없을 때
        if(parent[N-1]==-1){
            for(int i=0; i<N; ++i){
                for(int j=i+1; j<N; ++j){
                    if(capacity[i][j]>0 && capacity[i][j]==flow[i][j]){

                    }
                }
            }
            break;
        }
        int amount=987654321;
        for(int p=N-1; p!=0; p=parent[p]){
            amount=min(capacity[parent[p]][p]-flow[parent[p]][p], amount);
        }
        for(int p=N-1; p!=0; p=parent[p]){
            flow[parent[p]][p]+=amount;
            flow[p][parent[p]]-=amount;
        }
    }
}
int main() {
    int K;
    cin>>K;
    while(K--){
        cin>>N>>M;
        memset(capacity, 0, sizeof(capacity));
        for(int i=0; i<M; ++i){
            int f, t, b;
            cin>>f>>t>>b;
            f--; t--;
            capacity[f][t]=b;
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}