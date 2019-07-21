#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> times;
vector<vector<int>> adj;
vector<int> indegree;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K, W;
        cin>>N>>K;
        times=vector<int>(N);
        adj=vector<vector<int>>(N);
        indegree=vector<int>(N, 0);
        for(int i=0; i<N; ++i){
            cin>>times[i];
        }
        for(int i=0; i<K; ++i){
            int a, b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            indegree[b-1]++;
        }
        cin>>W;
        W--;
        queue<int> q;
        vector<int> ret(N, 0);
        for(int i=0; i<N; ++i){
            if(!indegree[i]){
                q.push(i);
                ret[i]=times[i];
                if(i==W){
                    q={};
                    break;
                }
            }
        }
        while(!q.empty()){
            int here=q.front();
            q.pop();
            for(int i=0; i<adj[here].size(); ++i){
                int there=adj[here][i];
                indegree[there]--;
                ret[there]=max(ret[there], ret[here]+times[there]);
                if(indegree[there]==0){
                    if(there==W){
                        break;
                    }
                    q.push(there);
                }
            }
        }

        cout<<ret[W]<<endl;
    }
    return 0;
}