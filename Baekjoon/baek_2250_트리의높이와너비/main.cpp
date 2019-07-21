#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tree[10001][2];
int pos[10001][2];
int parent[10001];

int N, root;
vector<vector<int>> lev(10000);

//bfs - LEVEL 찾기!
//왼쪽 개수랑 오른쪽 개수를 알아야 될 것 만 같은대
pair<int, int> longest={1,1};

// level
int height(int root){
    if(root==-1)
        return -1;
    int left=height(tree[root][0])+1;
    int right=height(tree[root][1])+1;
    pos[root][0]=left;
    pos[root][1]=right;
    return left+right;
}

void dfs(int root, int p, int level){
    if(root==-1)
        return;
    int left=tree[root][0];
    int right=tree[root][1];
    if(left!=-1) {
        int left_pos = p - pos[left][1] - 1;
        lev[level + 1].push_back(left_pos);
        dfs(left, left_pos, level+1);
    }
    if(right!=-1) {
        int right_pos = p + pos[right][0] + 1;
        lev[level + 1].push_back(right_pos);
        dfs(right, right_pos, level+1);
    }

}

void find_max(){
    for(int i=1; i<10001; ++i){
        if(lev[i].size()==0)
            break;
        //sort(lev[i].begin(), lev[i].end());
        int dist=0;
        if(lev[i].size()>=2)
            dist=lev[i][lev[i].size()-1]-lev[i][0]+1;
        if(dist>longest.second){
            longest.first=i+1;
            longest.second=dist;
        }
    }
}

int find_root(){
    for(int i=1; i<=N; ++i){
        if(parent[i]==0)
            return i;
    }
}
int main() {
    cin>>N;
    for(int i=0; i<N; ++i ){
        int root, left, right;
        cin>>root>>left>>right;
        tree[root][0]=left;
        tree[root][1]=right;
        if(left!=-1)
            parent[left]=1;
        if(right!=-1)
            parent[right]=1;
    }
    root=find_root();
    height(root);
    dfs(root, pos[root][0]+1, 0);
    find_max();
    cout << longest.first<<" " << longest.second;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}