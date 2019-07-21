#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

#define MAX 20000
int N, M, S, T;
int cache[MAX];
vector<vector<int>> adj;
vector<vector<int>> sccAdj;
vector<bool> sccVisited;
vector<int> sccId;
vector<int> sccCnt;
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
            sccCnt[sccCounter]++;
            if(t==here) break;
        }
        //sccAdj[sccId[parent]].push_back(sccCounter);
        ++sccCounter;
    }
    return ret;
}

vector<int> tarjanSCC(){
    discovered=vector<int>(N+1, -1);
    sccId=vector<int>(N+1, -1);
    sccCnt=vector<int>(N+1, 0);
    sccCounter=0;
    vertexCounter=0;
    for(int i=1; i<=N; ++i) {
        if(discovered[i]==-1)
            scc(i);
    }
    return sccId;
}

void makeSccGraph(){
    sccAdj.resize(sccCounter);
    bool visited[MAX];
    for(int i=1; i<=N; ++i){
        memset(visited, 0, sizeof(visited));
        for(auto j:adj[i]){
            if(sccId[i]==sccId[j])
                continue;
            if(visited[sccId[j]])
                continue;
            sccAdj[sccId[i]].push_back(sccId[j]);
            visited[sccId[j]]=true;
        }
    }
}


int main() {
    cin>>N>>M>>S>>T;
    memset(cache, 0, sizeof(cache));

    adj=vector<vector<int>>(N+1);

    for(int i=0; i<M; ++i){
        int A, B;
        cin>>A>>B;
        adj[A].push_back(B);
    }

    tarjanSCC();
    makeSccGraph();
    int s=sccId[S], e=sccId[T];
    cache[s]=sccCnt[s];

    for(int i=s; i>=0; --i ){
        for(auto j:sccAdj[i]){
            cache[j]=max(cache[j], sccCnt[j]+cache[i]);
        }
    }
    cout<<cache[e];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}