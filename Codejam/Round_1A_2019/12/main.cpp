#include <iostream>
#include <vector>

using namespace std;

int R, C, N;
bool visited[401];
bool adj[401][401];
vector<pair<int, int>> order;
// start point

void dfs(vector<pair<int, int>>& path, vector<vector<bool>>& visited, pair<int,int> here, int cnt){
    if(cnt==N)
        return;
    bool flag=false;
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            if(i==here.first || j==here.second || i-j==here.first-here.second || i+j==here.first+here.second)
                continue;
            if(!visited[i][j]){
                flag=true;
                visited[i][j]=true;
                path.push_back({i, j});
                dfs(path, visited, {i, j}, cnt+1);
                path.pop_back();
                visited[i][j]=false;
            }

        }
    }
    if(!flag)
        return

}

void dfsAll(){
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            vector<pair<int, int>> path;
            vector<vector<bool>> visited(N, vector<bool>(N, false));
            dfs(path, visited, {i,j}, 0);
        }
    }
}
int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cin>>R>>C;
        int maxV=(R, C);
        bool flag=false;
        order.clear();
        cout<<"Case #"<<t<<": ";
        if(maxV<4)
            cout<<"IMPOSSIBLE"<<'\n';
        else {
            if(R>C){
                swap(R, C);
                flag=true;
            }


            cout<<"POSSIBLE"<<'\n';
            for(auto p:order){
                cout<<p.first+1<<" "<<p.second+1<<'\n';
            }

        }

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}