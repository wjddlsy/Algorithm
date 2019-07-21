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

void solve(){
    vector<int> indegree(sccCounter);
    for(int i=0; i<N; ++i){
        for(int j=0; j<adj[i].size(); ++j){
            if(sccId[i]==sccId[adj[i][j]]) continue;
            indegree[sccId[adj[i][j]]]++;
        }
    }

    int cnt=0, index=0;
    for(int i=0; i<sccCounter; ++i){
        if(indegree[i]==0) {
            cnt++;
            index=i;
        }
    }


    if(cnt==1){
        for(int id=0; id<N; ++id){
            if(sccId[id]==index)
                cout<<id<<'\n';
        }
    }
    else
        cout<< "Confused" <<'\n';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        cin>>N>>M;
        adj=vector<vector<int>>(N);
        for(int i=0; i<M; ++i){
            int A, B;
            cin>>A>>B;
            adj[A].push_back(B);
        }
        tarjanSCC();
        solve();
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}