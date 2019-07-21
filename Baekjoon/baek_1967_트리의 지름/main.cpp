#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;

int longest;
bool visited[100001]={false,};
int height(int root){

    vector<int> heights;
    visited[root]=true;
    for(int i=0; i<adj[root].size(); ++i){
        if(!visited[adj[root][i].first])
            heights.push_back(adj[root][i].second+height(adj[root][i].first));
    }
    if(heights.empty()) return 0; //자식이 하나도 없는 경우!
    sort(heights.begin(), heights.end());
    if(heights.size()>=2)
        longest=max(longest, heights[heights.size()-2]+heights[heights.size()-1]);


    return heights.back();
}

int solve(int root){
    longest=0;
    int h=height(root);
    return max(longest, h);
}
int main() {
    int V;
    cin>>V;
    adj=vector<vector<pair<int, int>>>(V+1);
    for(int i=1; i<V; ++i){
        int root, a, b;
        cin>>root>>a>>b;
        adj[root].push_back({a,b});
    }
    cout<<solve(1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}