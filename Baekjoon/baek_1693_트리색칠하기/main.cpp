#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
int cache[100001][20]; //j번째 색으로 칠해진 루트 트리의 최소 비용 ㅎ;ㅎ;ㅎ;

//level 당 다른 색으로 칠하는게 ........아니
int n;
int go(int root, int parent){
    cache[root][0]=987654321;
    for(int i=1; i<20; ++i)
        cache[root][i]+=i; //내색이 무엇일까요
    for(int i=0; i<adj[root].size(); ++i){
        if(adj[root][i]==parent) continue;
        go(adj[root][i], root);
        int col1=0, col2=0; //자식이랑 색이 달라야됨
        for(int j=1; j<20; ++j){ //무슨색으로 칠할가요  후보 2개 저장
            if(cache[adj[root][i]][col2]>cache[adj[root][i]][j]) col2=j;
            if(cache[adj[root][i]][col1]>cache[adj[root][i]][col2]) swap(col1, col2);
        }
        for(int j=1; j<20; ++j) //자식이랑 다른색 칠하깅
            cache[root][j]+=cache[adj[root][i]][j!=col1?col1:col2];
    }
}
int main() {
    //int n;
    cin>>n;
    adj=vector<vector<int>>(n+1);
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    go(1, 0);//1번을 루트로하는 트리!
    int ret=987654321;
    for(int i=1; i<20; ++i){
        ret=min(ret, cache[1][i]);
    }

    cout<<ret;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}