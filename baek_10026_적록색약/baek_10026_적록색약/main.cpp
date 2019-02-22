//
//  main.cpp
//  baek_10026_적록색약
//
//  Created by 윤정인 on 2018. 7. 23..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, ret1=0, ret2=0;
int red=0, green=0, blue=0;
std::vector<std::string> in;
std::string input;
bool check[100][100];


bool isRange(int x, int y){
    if ( x >= n || y >=n || x<0 || y<0)
        return false;
    return true;
}

void count(int x, int y, char a){
    if(!isRange(x, y))
        return;
    if (check[x][y])
        return;
    
    
    if(in[x][y]!=a){
//        if ( (in[x][y]=='G' && a=='R') || (in[x][y]=='R' && a=='G')){
//            ret2--;
//            for (int direction=0; direction<4; ++direction){
//                int nextX=x+dx[direction], nextY=y+dy[direction];
//                count(nextX, nextY, in[x][y]);
//            }
//        }

        return;
    }
    
    check[x][y]=true;
    
    

    for (int direction=0; direction<4; ++direction){
        int nextX=x+dx[direction], nextY=y+dy[direction];
        count(nextX, nextY, in[x][y]);
    }
    
    return;
}

void count2(int x, int y, char a){
    if(!isRange(x, y))
        return;
    if (check[x][y])
        return;
    
    if(in[x][y]!=a){
        if ( !((in[x][y]=='G' && a=='R') || (in[x][y]=='R' && a=='G'))){
            return;
        }
    }
    
    check[x][y]=true;
    
    for (int direction=0; direction<4; ++direction){
        int nextX=x+dx[direction], nextY=y+dy[direction];
        count2(nextX, nextY, in[x][y]);
    }
    
    return;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin >> n;
    for (int i=0; i<n; ++i){
        std::cin >> input;
        in.push_back(input);
    }
    
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if(!check[i][j]){
                count(i, j, in[i][j]);
                if(in[i][j]=='R')
                    red++;
                else if (in[i][j]=='G')
                    green++;
                else
                    blue++;
                ret1++;
                //ret2++;
            }
        }
    }
    
    for (int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            check[i][j]=false;
    }
    
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if(!check[i][j]){
                count2(i, j, in[i][j]);
                //ret1++;
                ret2++;
            }
        }
    }
    
    std::cout << ret1 << " " << ret2;
    //std::cout << red << " " << green << " " << blue ;
    //std::cout << red+green+blue << " " << std::max(red, green)+blue ;
    return 0;
}
