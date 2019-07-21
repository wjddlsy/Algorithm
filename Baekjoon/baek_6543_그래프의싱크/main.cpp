#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> sccId, discovered;
stack<int> st;
vector<int> nodes;
vector<int> outdegree;
int sccCounter, vertexCounter;

// 역방향 간선이나 교차 ㅏㄱㄴ선을 통해 갈 수 있는 정점 중 최소 발견 순서 반환
int scc(int here){
    int ret=discovered[here]=vertexCounter++;
    st.push(here);
    for(auto there:adj[here]){
        if(discovered[there]==-1)
            ret=min(ret, scc(there));
        // 이미 방문했는데 안끝난 점이면 역방향.........
        else if(sccId[there]==-1)
            ret=min(ret, discovered[there]);
    }

    if(ret==discovered[here]){
        while(true){
            int t=st.top();
            st.pop();
            sccId[t]=sccCounter;
            if(t==here) {
                break;
            }
        }
        ++sccCounter;
    }
    return ret;
}

vector<int> tarjan(){
    sccId=discovered=vector<int>(n+1, -1);
    sccCounter=vertexCounter=0;
    nodes.resize(0);
    for(int i=1; i<=n; ++i) if(discovered[i]==-1) scc(i);
    return sccId;

}

void solve(){
    // scc인데 나가는 경로가 있으면 안됨
    vector<bool> isOutdegree=vector<bool>(sccCounter, 0);
    for(int i=1; i<=n; ++i){
        for(auto j:adj[i]){
            if(sccId[i]==sccId[j])
                continue;
            isOutdegree[sccId[i]]=true;
        }
    }

    for(int i=1; i<=n; ++i){
        if(!isOutdegree[sccId[i]])
            cout<<i<<" ";
    }
}
int main() {
    while(true){
        cin>>n;
        if(n==0)
            break;
        cin>>m;
        adj=vector<vector<int>>(n+1);
        outdegree=vector<int>(n+1, 0);
        for(int i=0; i<m; ++i){
            int v, w;
            cin>>v>>w;
            adj[v].push_back(w);
            outdegree[v]++;
        }
        tarjan();
        solve();
        cout<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}