#include <iostream>
#include <vector>
using namespace std;

int adj[1000][1000];
int degree[1000];
int N;
void getEulerCircuit(int here, vector<int>& ret){
    for(int there=0; there<N; ++there){
        while(adj[here][there]>0){
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, ret);
        }
    }
    ret.push_back(here);
}
int main() {
    //int N;
    cin>>N;
    int nEdge=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>adj[i][j];
            degree[i]+=adj[i][j];
            nEdge+=adj[i][j];
        }
        if(degree[i]%2==1){
            cout<<-1;
            return 0;
        }
    }
    vector<int> ret;
    getEulerCircuit(0, ret);

    if(ret.size()-1!=nEdge/2){
        cout<<-1;
        return 0;
    }
    for(auto r:ret){
        cout<<r+1<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}