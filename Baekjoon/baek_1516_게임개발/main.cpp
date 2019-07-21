#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> adj;
vector<int> times;
vector<int> indegree;
vector<int> ret;
queue<int> q;
int main() {
    int N;
    cin>>N;
    adj=vector<vector<int>>(N);
    //times=vector<int>(N, 0);
    indegree=vector<int>(N, 0);
    ret=vector<int>(N, 0);
    for(int i=0; i<N; ++i){
        int a;
        cin>>a;
        times.push_back(a);
        while(cin>>a){
            if(a==-1)
                break;
            adj[a-1].push_back(i);
            indegree[i]++;
        }
    }

    int currentTime=0;
    int tmp=0;
    for(int i=0; i<N; ++i){
        if(!indegree[i]) {
            tmp=max(tmp, times[i]);
            ret[i]=times[i];
            q.push(i);
        }
    }

    currentTime+=tmp;

    while(!q.empty()){
        tmp=0;
        int here=q.front();
        q.pop();
        for(int i=0; i<adj[here].size(); ++i){
            int there=adj[here][i];
            ret[there]=max(ret[there], ret[here]+times[there]);
            indegree[there]--;
            if(indegree[there]==0){
                q.push(there);
            }

        }
    }

    for(int i=0; i<N; ++i){
        cout<<ret[i]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}