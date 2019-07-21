#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here){
    int ret=discovered[here]=vertexCounter++;
    st.push(here);
    for(auto there:adj[here]){
        if(discovered[there]==-1)
            ret=min(ret, scc(there));
        else if(sccId[there]==-1)
            ret=min(ret, discovered[there]);
    }
    if(ret==discovered[here]){
        while(true){
            int t=st.top();
            st.pop();
            sccId[t]=sccCounter;
            if(t==here) break;
        }
        ++sccCounter;
    }
    return ret;
}

vector<int> tarjanSCC(){
    sccId=discovered=vector<int>(N, -1);
    sccCounter=vertexCounter=0;
    for(int i=0; i<N; ++i) if(discovered[i]==-1) scc(i);
    return sccId;
}

int solve(){
    vector<int> indegree(N);
    for(int i=0; i<N; ++i){
        for(int j=0; j<adj[i].size(); ++j){
            if(sccId[i]==sccId[adj[i][j]]) continue;
            indegree[sccId[adj[i][j]]]++;
        }
    }

    int ret=0;
    for(int i=0; i<sccCounter; ++i){
        if(indegree[i]==0)
            ret++;
    }
    return ret;

}
int main() {
    int T;
    cin>>T;
    while(T--){
        cin>>N>>M;
        adj=vector<vector<int>>(N);
        for(int i=0; i<M; ++i){
            int x, y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
        }
        tarjanSCC();

        cout<<solve()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}