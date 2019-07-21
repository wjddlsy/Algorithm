#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
priority_queue<int> pq;
vector<int> indegree;
vector<int> ret;
int main() {
    int N, M;
    cin>>N>>M;

    adj=vector<vector<int>>(N);
    indegree=vector<int>(N, 0);
    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        indegree[b-1]++;
    }
    for(int i=0; i<N; ++i){
        if(!indegree[i])
            pq.push(-i);
    }

    while(!pq.empty()){
        int here=-pq.top();
        pq.pop();
        ret.push_back(here);
        for(int i=0; i<adj[here].size(); ++i){
            int there=adj[here][i];
            indegree[there]--;
            if(indegree[there]==0){
                pq.push(-there);
            }
        }
    }
    for(int i=0; i<N; ++i){
        cout<<ret[i]+1<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}