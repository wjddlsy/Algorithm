#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
int main() {
    int T;
    cin>>T;
    while(T--){
        int K, M, P;
        cin>>K>>M>>P;
        adj=vector<vector<int>>(M+1);
        indegree=vector<int>(M+1, 0);
        for(int i=0; i<P; ++i){
            int A, B;
            cin>>A>>B;
            adj[A].push_back(B);
            indegree[B]++;
        }
        queue<int> q;
        vector<pair<int, int>> order(M+1);
        for(int i=1; i<=M; ++i){
            if(!indegree[i]) {
                q.push(i);
                order[i]={1, 0};
            }
        }
        while(!q.empty()){
            int here=q.front();
            q.pop();
            for(int i=0; i<adj[here].size(); ++i){
                int there=adj[here][i];
                indegree[there]--;
                if(order[here].first==order[there].first){
                    order[there].second=1;
                }
                else if(order[here].first>order[there].first){
                    order[there].second=0;
                    order[there].first=order[here].first;
                }
                //order[there]=max(order[there], order[here]);
                if(indegree[there]==0){
                    if(order[there].second==1)
                        order[there].first++;
                    q.push(there);
                }
            }
        }

        cout<<K<<" "<<order[M].first<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}