#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M;
stack<int> st;
vector<vector<int>> adj;
vector<int> sccId, discovered;
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
            if(t==here)
                break;
        }
        sccCounter++;
    }
    return ret;
}
void tarjan(){
    sccId=discovered=vector<int>((N+M)*2, -1);
    sccCounter=vertexCounter=0;
    for(int i=0; i<(N+M)*2; ++i){
        if(discovered[i]==-1) scc(i);
    }
}
int solve(){
    for(int i=0; i<N+M; ++i){
        if(sccId[2*i]==sccId[2*i+1])
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    vector<pair<int, int>> jewel, tracker;
    adj=vector<vector<int>>((N+M)*2);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            char c;
            cin>>c;
            int a=i, b=N+j;
            if(c=='*'){
                // i 행, j열
                adj[a*2+1].push_back(b*2);
                adj[b*2+1].push_back(a*2);
                adj[a*2].push_back(b*2+1);
                adj[b*2].push_back(a*2+1);
            }
            else if(c=='#'){
                adj[a*2].push_back(b*2);
                adj[b*2+1].push_back(a*2+1);
                adj[a*2+1].push_back(b*2+1);
                adj[b*2].push_back(a*2);
            }

        }
    }

    tarjan();
    cout<<solve();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}