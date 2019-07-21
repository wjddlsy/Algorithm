#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> discovered, sccId;
vector<vector<int>> adj;
int sccCounter, vertexCounter;
int N, M;
stack<int> st;
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
            if(t==here)
                break;
        }
        sccCounter++;
    }
    return ret;
}

void tarjan(){
    discovered=sccId=vector<int>(2*N+1, -1);
    sccCounter=vertexCounter=0;
    for(int i=1; i<=2*N; ++i){
        if(discovered[i]==-1)
            scc(i);
    }
}
string solve(){
    for(int i=1; i<=N; ++i){
        if(sccId[2*i]==sccId[2*i-1])
            return "Suspicious bugs found!";
    }
    return  "No suspicious bugs found!";
}
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>N>>M;
        cout<<"Scenario #"<<t<<":"<<'\n';
        adj=vector<vector<int>>(2*N+1);
        for(int i=0; i<M; ++i){
            int a, b;
            cin>>a>>b;
            adj[2*a].push_back(2*b-1);
            adj[2*a-1].push_back(2*b);
            adj[2*b].push_back(2*a-1);
            adj[2*b-1].push_back(2*a);
        }

        tarjan();
        cout<<solve()<<'\n';

        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}