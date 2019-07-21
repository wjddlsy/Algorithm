#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX 10000
int V, E;
vector<int> adj[MAX];
vector<int> sccId;
vector<vector<int>> sccPair;
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
            sccPair[sccCounter].push_back(t);
            if(t==here) break;
        }
        ++sccCounter;
    }
    return ret;
}

vector<int> tarjanSCC(){
    sccId=discovered=vector<int>(V, -1);
    sccPair=vector<vector<int>>(V);
    sccCounter=vertexCounter=0;
    for(int i=0; i<V; ++i) if(discovered[i]==-1) scc(i);
    return sccId;
}
int main() {
    cin>>V>>E;
    for(int i=0; i<E; ++i){
        int A, B;
        cin>>A>>B;
        adj[A-1].push_back(B-1);
    }
    vector<int> ret=tarjanSCC();
    cout<<sccCounter<<'\n';
    for(int i=0; i<sccCounter; ++i){
        sort(sccPair[i].begin(), sccPair[i].end());
    }

    sccPair.resize(sccCounter);

    sort(sccPair.begin(), sccPair.end(), [](vector<int> a, vector<int> b){
        return a[0]<b[0];
    });
    for(int i=0; i<sccCounter; ++i){
        for(auto pp:sccPair[i]){
            cout<<pp+1<<" ";
        }
        cout<<-1<<'\n';
    }
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}