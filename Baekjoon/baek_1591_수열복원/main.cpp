#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    int a;
    int b;
    vector<int> seq;

    Node(vector<int> seq){
        this->seq=seq;
        this->a=seq.front();
        this->b=seq.back();
    }
};

vector<vector<int>> adj;
vector<int> indegree, outdegree;
int N, M;

void getEulerCircuit(int here, vector<int>& circuit){
    for(int there=0; there<adj.size(); ++there){
        while(adj[here][there]>0){
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit(){
    vector<int> circuit;
    for(int i=0; i<adj.size(); ++i){
        if(outdegree[i]==indegree[i]+1){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    for(int i=0; i<adj.size(); ++i){
        if(outdegree[i]){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    map<string, int> m;
    map<int, string> retrieve;
    //vector<vector<string>> inputs;
    adj=vector<vector<int>>(2*(N-M+1), vector<int>(2*(N-M+1),0));
    outdegree=vector<int>(2*(N-M+1),0);
    indegree=vector<int>(2*(N-M+1),0);
    int key=0;
    for(int i=0; i<N-M+1; ++i) {
        string a = "", b = "";
        for (int j = 0; j < M; ++j) {
            string c;
            cin >> c;
            if (j < M - 1)
                a += c + " ";
            if (j > 0)
                b += c + " ";
        }

        if(m.find(a)==m.end()) {
            retrieve[key]=a;
            m[a] = key++;
        }
        if(m.find(b)==m.end()) {
            retrieve[key]=b;
            m[b] = key++;
        }
        adj[m[a]][m[b]]++;
        indegree[m[b]]++;
        outdegree[m[a]]++;
    }
    vector<int> ret=getEulerTrailOrCircuit();
    reverse(ret.begin(), ret.end());


    for(int i=0; i<ret.size(); ++i){
        string s=retrieve[ret[i]];
        if(i==ret.size()-1){
            cout<<s;
        }
        else
            cout<<s.substr(0, s.find(" ")+1);

    }

    return 0;
}
//int main() {
//    //int N, M;
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cin>>N>>M;
//
//    adj=vector<vector<int>>(N-M+1, vector<int>(N-M+1, 1));
//    indegree=vector<int>(N-M+1, (N-M));
//    outdegree=vector<int>(N-M+1, (N-M));
//
//    vector<Node> nodes;
//
//    for(int i=0; i<N-M+1; ++i){
//        vector<int> seq(M);
//
//        for(int i=0; i<M; ++i){
//            cin>>seq[i];
//        }
//        Node node(seq);
//        nodes.push_back(node);
//    }
//
//    for(int i=0; i<N-M+1; ++i){
//        for(int j=0; j<N-M+1; ++j){
//            if(i==j){
//                adj[i][j]=0;
//            }
//            else {
//                for (int k = 0; k < M - 1; ++k) {
//                    if (nodes[i].seq[k + 1] != nodes[j].seq[k]) {
//                        adj[i][j] = 0;
//                        outdegree[i]--;
//                        indegree[j]--;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//
//    vector<int> ret=getEulerTrail();
//
//    for(int i=N-M; i>=0; --i){
//        if(i==0){
//            for(int j=0; j<M; ++j)
//                cout<<nodes[ret[i]].seq[j]<<" ";
//        }
//        else
//            cout<<nodes[ret[i]].a<<" ";
//    }
//    //std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
