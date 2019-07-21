#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj;
int S,E;

bool decision(int w) {
    vector<bool> discovered(adj.size(), false);
    queue<int> q;
    q.push(S);
    discovered[S]=true;
    while(!q.empty()) {
        int here=q.front();
        q.pop();
        if(here==E)
            return true;
        for(auto &there:adj[here]) {
            if(discovered[there.first])
                continue;
            if(there.second<w)
                continue;
            q.push(there.first);
            discovered[there.first]=true;
        }
    }
    return false;
}

long long optimize() {
    long long lo=0, hi=1000000000;
    while(lo<=hi){
        long long mid=(lo+hi)/2;
        if(decision(mid)) {
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }
    return hi;
}
int main() {
    int N, M;
    cin>>N>>M;
    adj.resize(N);
    for(int i=0; i<M; ++i){
        int A,B,C;
        cin>>A>>B>>C;
        A--; B--;
        adj[A].emplace_back(B, C);
        adj[B].emplace_back(A, C);
    }
    cin>>S>>E;
    S--; E--;

    long long ans=optimize();
    cout<<ans;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}