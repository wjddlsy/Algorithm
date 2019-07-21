#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> discovered, sccId;
stack<int> st;
int sccCounter, vertexCounter;

// here을 루트로 하는 서브트리에서 역방향 간선이나 교차간선을 통해 갈 수 있는 정점 중 최소 발견 순서 반환
int scc(int here){
    int ret=discovered[here]=vertexCounter++;
    st.push(here);
    for(auto there:adj[here]){
        if(discovered[there]==-1){
            ret=min(ret, scc(there));
        }
        else if(sccId[there]==-1){
            ret=min(ret, discovered[there]);

        }
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

void tarjan(){
    int n=2*N;
    discovered=sccId=vector<int>(n+1, -1);
    sccCounter=vertexCounter=0;
    for(int i=1; i<=n; ++i){
        if(discovered[i]!=-1)
            continue;
        scc(i);
    }

}

bool solve(){
    for(int i=1; i<=N; ++i){
        if(sccId[i*2]==sccId[i*2-1]){
            return false;
        }
    }
    return true;
}
int main() {
    cin>>N>>M;
    adj=vector<vector<int>>(2*N+1);
    for(int m=0; m<M; ++m){
        int i, j;
        cin>>i>>j;
        i<0?i=(-i*2):i=(i*2-1);
        j<0?j=(-j*2):j=(j*2-1);
        if(i%2==1){
            adj[i+1].push_back(j);
        }
        else
            adj[i-1].push_back(j);
        if(j%2==1){
            adj[j+1].push_back(i);
        }
        else
            adj[j-1].push_back(i);
    }

    tarjan();

    cout<<solve();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}