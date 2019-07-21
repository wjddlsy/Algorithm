#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
const int INF=987654321;
vector<vector<pair<int, int>>> adj;
vector<pair<int, pair<int, int>>> edges;
vector<int> weights;

struct DisjointSet{
    int n;
    vector<int> parent;
    DisjointSet(int n):n(n){
        for(int i=0; i<n; ++i)

    }
};

bool hasPath(int lo, int hi){
    queue<int> q;
    vector<bool> discovered(N, false);
    q.push(0);
    discovered[0]=true;
    while(!q.empty()){
        int here=q.front();
        q.pop();
        if(here==N-1)
            return true;
        for(auto t:adj[here]){
            int there=t.first;
            int cost=t.second;
            if(discovered[there])
                continue;
            if(cost>=lo && cost<=hi){
                q.push(there);
                discovered[there]=true;
            }

        }
    }
    return false;
}

int binarySearchMinUpperBound(int low){
    int lo=low-1, hi=weights.size();
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(hasPath(weights[low], weights[mid]))
            hi=mid;
        else
            lo=mid;
    }
    if(hi==weights.size()) return INF;
    return weights[hi];
}

int kruscalMinUpperBoudn(int low){

}
int minWeightDifference(){
    int ret=INF;
    for(int i=0; i<weights.size(); ++i){
        ret=min(ret, binarySearchMinUpperBound(i)-weights[i]);
    }
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>N>>M;
        adj=vector<vector<pair<int, int>>>(N);
        weights.clear();
        for(int i=0; i<M; ++i){
            int a, b, c;
            cin>>a>>b>>c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            weights.push_back(c);

            edges.push_back({c, {a, b}});
            edges.push_back({c, {a, c}});
        }
        sort(weights.begin(), weights.end());
        sort(edges.begin(), edges.end());
        cout<<minWeightDifference()<<'\n';
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}