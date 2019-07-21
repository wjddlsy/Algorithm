#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1. 그래프로 표현하기
vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;
bool disjoint(const pair<int, int>& a, const pair<int, int>& b){
    return a.second<=b.first || b.second<=a.first;
}
void makeGraph(const vector<pair<int, int>>& meetings){
    int vars=meetings.size();
    adj.clear(); adj.resize(vars*2);
    for(int i=0; i<vars; ++i){
        int j=i+1;
        adj[i*2+1].push_back(j*2);
        adj[j*2+1].push_back(i*2);
    }
    for(int i=0; i<vars; ++i){
        for(int j=0; j<i; ++j){
            if(!disjoint(meetings[i], meetings[j])){
                adj[i*2].push_back(j*2+1);
                adj[j*2].push_back(i*2+1);
            }
        }
    }
}

int scc(int here){
    int ret=discovered[here]=vertexCounter++;
    st.push(here);
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
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
            if(t==here) break;
        }
        ++sccCounter;
    }
    return ret;
}
vector<int> tarjanSCC(){
    sccId=discovered=vector<int>(adj.size(), -1);
    sccCounter=vertexCounter=0;
    for(int i=0; i<adj.size(); ++i){
        if(discovered[i]==-1) scc(i);
    }
    return sccId;
}
vector<int> solve2SAT(){
    int n=adj.size() /2;
    vector<int> label=tarjanSCC();
    for(int i=0; i<2*n; i+=2){
        if(label[i]==label[i+1])
            return vector<int>();
    }
    vector<int> value(2*n, -1);
    vector<pair<int, int>> order;
    for(int i=0; i<2*n; ++i){
        order.push_back({-label[i], i});
    }
    sort(order.begin(), order.end());
    for(int i=0; i<2*n; ++i){
        int vertex=order[i].second;
        int variable=vertex/2, isTrue=vertex%2==0;
        if(value[variable]!=-1) continue;
        value[variable]=!isTrue;
    }
    return value;
}

int main() {
    int C;
    cin>>C;
    while(C--){
        int N;
        cin>>N;
        vector<pair<int, int>> meetings;
        for(int i=0; i<N; ++i){
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            meetings.push_back({a,b});
            meetings.push_back({c,d});
        }

        makeGraph(meetings);
        vector<int> ret=solve2SAT();
        if(ret.empty())
            cout<<("IMPOSSIBLE")<<'\n';
        else {
            cout<<("POSSIBLE")<<'\n';
            for(int i=0; i<ret.size(); ++i){
                if(ret[i]!=1 && ret[i+1]!=0)
                    cout<<meetings[i].first<<meetings[i].second<<'\n';
                else
                    cout<<meetings[i+1].first<<meetings[i+1].second<<'\n';
            }
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}