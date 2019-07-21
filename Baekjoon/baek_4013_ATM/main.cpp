#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

#define MAX 10000

int N, M, S, P;

vector<vector<int>> adj;
vector<int> cash;
vector<int> restaurant;
vector<vector<int>> sccAdj;
vector<int> sccId;
vector<int> discovered;
vector<int> sccCash;
stack<int> st;
int cache[MAX];
int sccCounter, vertexCounter;

int scc(int here){
    int ret=discovered[here]=vertexCounter++;
    st.push(here);
    for(auto there:adj[here]){
        //야직 방문하지 않은 이웃
        if(discovered[there]==-1)
            ret=min(ret, scc(there));
        //방문은 했으나 아직 SCC로 추출되지 않은 이웃
        else if(sccId[there]==-1)
            ret=min(ret, discovered[there]);
    }
    // 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if(ret==discovered[here]){
        //스택에서 자신이 나올때까지 pop
        while(true){
            int t=st.top();
            st.pop();
            sccId[t]=sccCounter;
            sccCash[sccCounter]+=cash[t];
            if(t==here) break;
        }

        ++sccCounter;
    }
    return ret;
}

vector<int> tarjanSCC(){
    discovered=vector<int>(N+1, -1);
    sccId=vector<int>(N+1, -1);
    sccCash=vector<int>(N+1, 0);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    adj.resize(N+1);
    cash.resize(N+1);
    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1; i<=N; ++i){
        cin>>cash[i];
    }
    cin>>S>>P;
    for(int i=0; i<P; ++i){
        int p;
        cin>>p;
        restaurant.push_back(p);
    }


    tarjanSCC();
    makeSccGraph();

    memset(cache, 0, sizeof(cache));

    int s=sccId[S];
    cache[s]=sccCash[s];

    for(int i=s; i>=0; --i ){
        for(auto j:sccAdj[i]){
            cache[j]=max(cache[j], sccCash[j]+cache[i]);
        }
    }

    int ret=0;
    for(auto rest:restaurant){
        ret=max(ret, cache[sccId[rest]]);
    }

    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}