#include <iostream>
#include <vector>

using namespace std;

const int MAX=400;

int adj[MAX][MAX];
bool go[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , k, s;
    cin>>n>>k;
    for(int i=0; i<k; ++i){
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a][b]=1;
    }


    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                adj[i][j]= (adj[i][j] || (adj[i][k] && adj[k][j])) ;
            }
        }
    }

    cin>>s;
    for(int i=0; i<s; ++i){
        int a, b;
        cin>>a>>b;
        a--; b--;
        if(adj[a][b]==0 && adj[b][a]==0)
            cout<<0;
        else if(adj[a][b]==1)
            cout<<-1;
        else
            cout<<1;
        cout<<'\n';
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
