//
//  main.cpp
//  baek_6593_상범빌딩
//
//  Created by 윤정인 on 2018. 8. 12..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

int dx[]={1,-1,0,0,0,0}, dy[]={0,0,1,-1,0,0}, dz[]={0,0,0,0,1,-1};

using namespace std;

struct where{
    int x, y, z;
};

char building[30][30][30];

int l, r ,c;

bool isRange(where w){
    if (w.x <0 || w.x>=l || w.y<0 || w.y >=r || w.z<0 || w.z>=c)
        return false;
    return true;
    
}
void bfs(where start, where end){
    //bool isFind=false;
    queue<pair<where, int>> q;
    bool discovered[30][30][30];
    
    for (int i=0; i<l; ++i ){
        for (int j=0; j<r; j++){
            for (int k=0; k<c; ++k){
                discovered[i][j][k]=false;
            }
        }
    }
    discovered[start.x][start.y][start.z]=true;
    q.push(make_pair(start,0));
    
    while(!q.empty()){
        where here=q.front().first;
        int dist = q.front().second;
        q.pop(); //방문은 여기서 하는건댕 ...
        
        for (int i=0; i<6; ++i){
            where there;
            there.x=here.x + dx[i];
            there.y=here.y+dy[i];
            there.z=here.z+dz[i];
            if(building[there.x][there.y][there.z]!='#' && isRange(there) && !discovered[there.x][there.y][there.z]){
                int temp= dist;
                temp++;
                q.push(make_pair(there, temp));
                discovered[there.x][there.y][there.z]=true;
                
                if(there.x==end.x && there.y==end.y && there.z==end.z){
                    cout << "Escaped in " + to_string(temp) + " minute(s)." << '\n';
                    return;
                }
            }
            
        }
    }
    
    cout << "Trapped!" << '\n';
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    cin >> l >> r >> c;
    while(!(l==0 && r==0 && c==0)){
        where start, end;
        for (int i=0; i<l; ++i ){
            for (int j=0; j<r; j++){
                for (int k=0; k<c; ++k){
                    cin >> building[i][j][k];
                    if (building[i][j][k]=='S'){
                        start.x=i; start.y=j; start.z=k;
                    }
                    else if (building[i][j][k]=='E'){
                        end.x=i; end.y=j; end.z=k;
                    }
                }
            }
        }
    
        bfs(start, end);
        cin >> l >> r >> c;
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
