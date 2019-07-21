#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF=987654321;
int N, M;
vector<vector<pair<int, int>>> adj;

vector<int> bellmanford(){
    vector<int> upper(N, INF);
    upper[0]=0;
    bool updated;
    for(int iter=0; iter<N; ++iter) {
        updated=false;
        for (int here = 0; here < N; ++here) {
            for (auto t:adj[here]) {
                int there = t.first;
                int cost = t.second;
                if(upper[here]!=INF) {
                    if (upper[there] > upper[here] + cost) {
                        upper[there] = upper[here] + cost;
                        updated = true;
                    }
                }
            }
        }
        if(!updated) break;
    }
    if(updated) upper.clear();
    return upper;
}
int main() {
    cin>>N>>M;
    adj.resize(N);
    int r=0;
    for(int i=0; i<M; ++i){
        int A, B, C;
        cin>>A>>B>>C;
        A--; B--;
        adj[A].push_back({B, C});
        if(C<0)
            r+=C;
    }
    vector<int> ret=bellmanford();
    if(ret.empty()) cout<<-1;

    else {
        for(int i=1; i<ret.size(); ++i){
            if(ret[i]>=INF)
                cout<<-1<<'\n';
            else
                cout<<ret[i]<<'\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}