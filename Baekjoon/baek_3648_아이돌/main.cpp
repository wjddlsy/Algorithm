#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> discovered, sccId;
stack<int> st;
int sccCounter, vertexCounter;

int another(int index){
    return index%2==1?index+1:index-1;
}

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
        if(sccId[2*i]==sccId[2*i-1])
            return false;
    }
    return true;
}

int main() {
    while(cin>>N) {
        cin >> M;
        adj = vector<vector<int>>(2 * N + 1);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            a = a < 0 ? -a * 2 : a * 2 - 1;
            b = b < 0 ? -b * 2 : b * 2 - 1;
            adj[another(a)].push_back(b);
            adj[another(b)].push_back(a);
        }
        adj[2].push_back(1);

        tarjan();
        bool value = solve();
        if (!value) {
            cout << "no";
        }
        else
            cout << "yes";
        cout<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}