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

vector<int> solve(){
    for(int i=1; i<=N; ++i){
        if(sccId[2*i]==sccId[2*i-1])
            return vector<int>();
    }
    vector<int> value(2*N+1, -1);
    vector<pair<int, int>> order;
    for(int i=1; i<=2*N; ++i){
        order.push_back({-sccId[i], i});
    }
    sort(order.begin(), order.end());
    for(int i=0; i<2*N; ++i){
        int vertex=order[i].second;
        int variable=(vertex+1)/2, isTrue=(vertex%2==1);
        if(value[variable]!=-1) continue;
        value[variable]=!isTrue;
    }
    return value;
}
int main() {
    cin>>N>>M;
    adj=vector<vector<int>>(2*N+1);
    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        a=a<0?-a*2:a*2-1;
        b=b<0?-b*2:b*2-1;
        adj[another(a)].push_back(b);
        adj[another(b)].push_back(a);
    }

    tarjan();
    vector<int> value=solve();
    if(value.empty()){
        cout<<0;
        return 0;
    }
    cout<<1<<'\n';
    for(int i=1; i<=N; ++i){
        cout<<value[i]<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}