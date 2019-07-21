#include <iostream>
#include <vector>
using namespace std;

int N;
bool adj[100][100];
int visited[100];
int cnt=0;

void dfs(int here){
    if(visited[here]!=-1)
        return;
    visited[here]=cnt;
    for(int i=0; i<N; ++i){
        if(!adj[here][i])
            continue;
        dfs(i);
    }
}
int dfsAll(){
    memset(visited, -1, sizeof(visited));
    for(int i=0; i<N; ++i){
        if(visited[i]!=-1)
            continue;
        dfs(i);
        cnt++;
    }
}
int main() {
    cin>>N;
    for(int i=0; i<N; ++i){
        int a;
        while(true){
            cin>>a;
            if(a==0)
                break;
            a--;
            adj[i][a]=true;
            adj[a][i]=true;

        }
    }
    dfsAll();
    // 서로 거리가 1이어야 ...

    // 2개 이상으로 나누어지면 불가능
    if(cnt>2)
        cout<<"No solution";
        // 2개면 그냥 그대로
    else if(cnt==2){
        vector<vector<int>> group(2);
        for(int i=0; i<N; ++i){
            int index=visited[i];
            group[index].emplace_back(i);
        }
        for(auto &g:group){
            cout<<g.size()<<" ";
            for(auto &p:g){
                cout<<p+1<<" ";
            }
            cout<<'\n';
        }
    }
        // 하나면 그냥 반반
    else {
        int cut=N/2;
        cout<<cut<<" ";
        for(int i=0; i<cut; ++i){
            cout<<i+1<< " ";
        }
        cout<<'\n';
        cout<<N-cut<<" ";
        for(int i=cut; i<N; ++i){
            cout<<i+1<<" ";
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}