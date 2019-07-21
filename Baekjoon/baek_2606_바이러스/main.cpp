#include <iostream>
#include <string.h>
#define INF 9876543
using namespace std;


bool adj[100][100]={false,};

void floyd(int n){
    for(int i=0; i<n; ++i) adj[i][i]=false;
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                adj[i][j]=(adj[i][j]|| (adj[i][k]&&adj[k][j]));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(adj,false,sizeof(adj));
    int n, c;
    cin>>n>>c;
    while(c--){
        int a,b;
        cin>>a>>b;
        adj[a-1][b-1]=true;
        adj[b-1][a-1]=true;
    }


    floyd(n);
    int cnt=0;
    for(int i=1; i<n; ++i){
        if(adj[0][i])
            cnt++;
    }
    cout<<cnt;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}