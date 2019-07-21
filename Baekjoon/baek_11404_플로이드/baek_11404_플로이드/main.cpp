//
//  main.cpp
//  baek_11404_플로이드
//
//  Created by 윤정인 on 2018. 8. 7..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>

#define INF 987654321


using namespace std;

vector<vector<int>> adj;


int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    
    adj=vector<vector<int>>(n, vector<int>(n, INF));
    
    for (int i=0; i<m; ++i){
        cin >> a >> b >> c ;
        adj[a-1][b-1]=min(adj[a-1][b-1],c);
        if (i<n)
            adj[i][i]=0;
    }
    
    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if (adj[i][j]==INF)
                cout << 0 << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
