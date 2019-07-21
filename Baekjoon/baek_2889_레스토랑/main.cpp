#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;



vector<int> adj[100001];
int degree[100001];
vector<vector<int>> components;
bool visited[100001];
unordered_map<pair<int, int>, bool, pair_hash> edgeVisited;
unordered_map<pair<int, int>, int, pair_hash> indexRoad;
int ret[100001];
int N, E, nRoad;



void getEulerCircuit(int here, vector<int>& circuit){
    for(auto there:adj[here]){
        int a=min(here, there), b=max(here, there);
        if(edgeVisited[{a, b}])
            continue;
        edgeVisited[{a, b}]=true;
        getEulerCircuit(there, circuit);
    }
    circuit.push_back(here);
}
// component 분류
void dfs(int here, vector<int>& nodes){
    if(visited[here]) return;
    visited[here]=true;
    nodes.push_back(here);
    for(int i=0; i<adj[here].size(); ++i){
        int there=adj[here][i];
        dfs(there, nodes);
    }
}

void dfsAll(){
    for(int i=0; i<N; ++i){
        if(visited[i])
            continue;
        vector<int> nodes;
        dfs(i, nodes);
        components.push_back(nodes);
    }
}

int number=1;
void makeResult(vector<int>& circuit){
    for(int i=0; i<circuit.size()-1; ++i){
        int here=circuit[i], there=circuit[i+1];
        if(here==N || there==N)
            continue;
        if(here>there)
            swap(here, there);
        number==1?number=2:number=1;
        ret[indexRoad[{here, there}]]=number;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>E;
    //adj=vector<vector<int>>(N+1);
    //degree=vector<int>(N, 0);
    //visited=vector<bool>(N+1, 0);
    //ret=vector<int>(E, 0);
    //Road=0;
    for(int i=0; i<E; ++i){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        degree[a-1]++; degree[b-1]++;
        nRoad++;
        if(a>b) swap(a, b);
        indexRoad[{a-1, b-1}]=i;
    }

    dfsAll();

    vector<int> circuit;
    for(int i=0; i<components.size(); ++i){
        bool flag=true;
        bool isOdds=false;
        int start=0;
        vector<int> nodes=components[i];
        for(auto here:nodes){
            if(degree[here]%2==1){
                isOdds=true;
                adj[here].push_back(N);
                adj[N].push_back(here);
            }
            else if(degree[here]>=4)
                start=here;

            if(degree[here]!=2)
                flag=false;
        }
        if(flag && nRoad%2) {
            cout << 0;
            return 0;
        }

        if(isOdds)
            getEulerCircuit(N, circuit);
        else
            getEulerCircuit(start, circuit);

    }

    makeResult(circuit);
    for(auto r:ret){
        cout<<r<<'\n';
    }
    // 홀수 도로에 대해 도시 ㅁ만들기
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}