#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;
int N;
void makeGraph(vector<string>& words){
    adj=vector<vector<int>>(26, vector<int>(26,0));
    for(int i=1; i<words.size(); ++i){
        int n= (int) min(words[i].size(), words[i-1].size());
        for(int j=0; j<n; ++j){
            if(words[i][j]!=words[i-1][j]){
                adj[words[i-1][j]-'a'][words[i][j]-'a']=1;
                break;
            }
        }
    }
}

void dfs(int here){
    visited[here]=true;
    for(int i=0; i<26; ++i){
        if(!visited[i]&&adj[here][i])
            dfs(i);
    }
    order.push_back(here);
}

bool topologicalSort(){
    visited=vector<bool>(26, 0);
    order.clear();
    for(int i=0; i<adj.size(); ++i){
        if(!visited[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
    //모순 찾기
    for(int i=0; i<adj.size(); ++i){
        for(int j=i+1; j<adj.size(); ++j){
            if(adj[order[j]][order[i]])
                return false;
        }
    }
    return true;
}
int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>N;
        vector<string> words;
        for(int i=0; i<N; ++i){
            string s;
            cin>>s;
            words.push_back(s);
        }
        makeGraph(words);
        if(topologicalSort()){
            for(int i=0; i<order.size(); ++i)
                cout<<(char)(order[i]+'a');
            cout<<'\n';
        } else
            cout<<"INVALID HYPOTHESIS"<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}