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
    discovered=sccId=vector<int>(2*M+1, -1);
    sccCounter=vertexCounter=0;
    for(int i=1; i<=2*M; ++i){
        if(discovered[i]==-1)
            scc(i);
    }
}
int solve(){
    for(int i=1; i<=M; ++i){
        if(sccId[2*i]==sccId[2*i-1])
            return 0;
    }
    return  1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    int on[100001];
    vector<vector<int>> sw(N+1);
    adj=vector<vector<int>>(2*M+1);
    for(int i=1; i<=N; ++i){
        cin>>on[i];
    }
    for(int i=1; i<=M; ++i){
        int K;
        cin>>K;
        for(int j=0; j<K; ++j){
            int num;
            cin>>num;
            sw[num].push_back(i);
        }
    }

    for(int i=1; i<=N; ++i){
        int a=sw[i][0], b=sw[i][1];
        if(on[i]){
            adj[a*2-1].push_back(b*2-1);
            adj[b*2].push_back(a*2);
            adj[a*2].push_back(b*2);
            adj[b*2-1].push_back(a*2-1);
        }
        else{
            adj[a*2].push_back(b*2-1);
            adj[b*2].push_back(a*2-1);
            adj[a*2-1].push_back(b*2);
            adj[b*2-1].push_back(a*2);
        }
    }
    tarjan();
    cout<<solve();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}