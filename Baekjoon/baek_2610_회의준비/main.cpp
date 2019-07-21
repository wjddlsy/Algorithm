#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=1000000;
int adj[100][100];
int N;

int main() {
    int M;
    cin>>N>>M;


    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            adj[i][j]=INF;
        }
        adj[i][i]=0;
    }


    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a][b]=adj[b][a]=1;
    }


    for(int k=0; k<N; ++k){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    int team[100]={0};
    int teamBoss[100][100];
    memset(teamBoss, -1, sizeof(teamBoss));
    int teamIndex=0;

    for(int i=0; i<N; ++i){
        bool makeTeam=true;
        for(int j=0; j<N; ++j){
            if(adj[i][j]!=INF && team[j]==0){
                if(makeTeam){
                    teamIndex++;
                    makeTeam=false;
                }
                team[i]=team[j]=teamIndex;
            }
            if(adj[i][j]!=INF)
                teamBoss[team[i]][i]=max(teamBoss[team[i]][i], adj[i][j]);
        }

    }

    vector<int> boss;
    for(int i=1; i<=teamIndex; ++i){
        int minValue=987654321;
        int minIndex=0;
        for(int j=0; j<N; ++j){
            if(teamBoss[i][j]!=-1 && minValue>teamBoss[i][j]){
                minIndex=j;
                minValue=teamBoss[i][j];
            }

        }
        boss.push_back(minIndex+1);
    }
    cout<<teamIndex<<'\n';
    sort(boss.begin(), boss.end());
    for(auto b:boss){
        cout<<b<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}