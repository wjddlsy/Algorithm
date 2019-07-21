//
//  main.cpp
//  baek_2660_회장뽑기
//
//  Created by 윤정인 on 2018. 8. 12..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int adj[50][50];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, a=0, b=0;
    cin >> n;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j)
            if(i!=j)
                adj[i][j]=INF;
    }
    while(true){
        cin >> a >> b;
        if(a==-1 && b==-1)
            break;
        adj[a-1][b-1]=1;
        adj[b-1][a-1]=1;
    }
    
    for (int k=0; k<n; ++k){
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j)
                if(adj[i][j]>adj[i][k] + adj[k][j])
                    adj[i][j]=adj[i][k]+adj[k][j];
        }
    }
   
    int minScore = n;
    vector<int> elected;
    for(int i=0; i < n; i++)
    {
        int score = 0;
        for(int j=0; j < n; j++)
            score = max(score, adj[i][j]);
        
        if(minScore > score)
        {
            minScore = score;
            elected.clear();
        }
        if(minScore == score)
            elected.push_back(i);
    }
    
    cout << minScore << " " << elected.size()<< endl;;
    
    for (auto x : elected){
        cout << x + 1 << " ";
    }
    return 0;
}


