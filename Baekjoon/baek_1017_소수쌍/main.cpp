#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool adj[50][50];
vector<int> aMatch, bMatch;
vector<bool> visited;
bool dfs(int a, int n){
    if(visited[a]) return false;
    visited[a]=true;
    for(int b=0; b<n; ++b){
        if(adj[a][b]){
            if(bMatch[b]==-1 || dfs(bMatch[b], n)){
                aMatch[a]=b;
                bMatch[b]=a;
                return true;
            }
        }
    }
    return false;
}
int bipartiteMatch(int n, int matched){
    aMatch=vector<int>(n, -1);
    bMatch=vector<int>(n, -1);
    aMatch[0]=matched;
    bMatch[matched]=0;
    int size=0;
    for(int start=0; start<n; ++start){
        visited=vector<bool>(n, false);
        visited[0]=true;
        if(dfs(start, n))
            ++size;
    }
    return size;
}
bool isPrime(int n){
    for(int i=2; i<n/2; ++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<int> first, second;
    bool flag=false;
    for(int i=0; i<N; ++i){
        int n;
        cin>>n;
        if(i==0 && n%2==0)
            flag=true;
        n%2==0?first.emplace_back(n):second.emplace_back(n);
    }
    if(first.size()!=second.size()){
        cout<<-1;
        return 0;
    }
    if(!flag)
        swap(first, second);
    // 홀/짝으로 그룹을 나눈다고 합니다 헐랭...
    for(int i=0; i<first.size(); ++i){
        for(int j=0; j<second.size(); ++j){
            if(isPrime(first[i]+second[j])){
                adj[i][j]=true;
            }
        }
    }
    vector<int> ret;
    int size=first.size();
    for(int i=0; i<second.size(); ++i){
        int flow=0;
        if(adj[0][i]){
            flow=bipartiteMatch(size, i)+1;
            if(flow==size)
                ret.emplace_back(second[i]);
        }
    }
    if(ret.empty())
        cout<<-1;
    else {
        sort(ret.begin(), ret.end());
        for(auto r:ret){
            cout<<r<<" ";
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}