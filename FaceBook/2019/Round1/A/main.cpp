#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int N, M;
vector<tuple<int, int, int>> require;

struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) : parent(n) {
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
    }
    int find(int u) {
        if(u==parent[u])
            return u;
        return parent[u]=find(parent[u]);
    }
    void merge(int u, int v) {
        u=find(u); v=find(v);
        if(u==v) return;
        parent[u]=v;
    }
};
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        cin>>N>>M;
        require.clear();
        vector<vector<int>> dist(N, vector<int>(N, 987654321));
        for(int i=0; i<M; ++i){
            int x, y, z;
            cin>>x>>y>>z;
            x--; y--;
            require.emplace_back(z, x, y);
            dist[x][y]=z;
            dist[y][x]=z;
        }
        sort(require.begin(), require.end());
        DisjointSet sets(N);
        vector<vector<int>> adj(N, vector<int>(N, 987654321));
        vector<tuple<int, int, int>> selected;
        for(int i=0; i<require.size(); ++i) {
            int z, x, y;
            tie(z, x, y)=require[i];
            if(sets.find(x)==sets.find(y)) continue;
            sets.merge(x, y);
            adj[x][y]=z;
            adj[y][x]=z;
            selected.emplace_back(x, y, z);
        }
        for(int i=0; i<N; ++i){
            adj[i][i]=0;
        }
        for(int k=0; k<N; ++k) {
            for(int i=0; i<N; ++i) {
                for(int j=0; j<N; ++j) {
                    adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        bool flag=true;
        for(int i=0; i<N; ++i) {
            for(int j=i+1; j<N; ++j) {
                if(dist[i][j]==987654321)
                    continue;
                if(adj[i][j]<dist[i][j]) {
                    flag=false;
                    break;
                } else if (adj[i][j]>dist[i][j]){
                    selected.emplace_back(i, j, dist[i][j]);
                }
            }
        }
        if(!flag) {
            cout<<"Impossible"<<'\n';
        } else {
            cout<<selected.size()<<'\n';
            for(auto &s:selected) {
                int x, y, z;
                tie(x, y, z)=s;
                cout<<x+1<<" "<<y+1<<" "<<z<<'\n';
            }
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}