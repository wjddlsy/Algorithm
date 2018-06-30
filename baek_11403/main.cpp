//
//  main.cpp
//  baek_11403
//
//  Created by 윤정인 on 2018. 6. 26..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

int n;
bool graph[100][100];
bool check[100][100];

void isRoute(int top, int x, int y){
    // 기저사례
    check[top][y]=true;
    for (int i=0; i<n; ++i){
        if(!check[top][i] && graph[y][i])
            isRoute(top, y, i);
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin >> n;
    
    for (int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            std::cin >> graph[i][j];
    }
    
    for (int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            if(!check[i][j] && graph[i][j])
                isRoute(i,i,j);
    }
    
    for (int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            std::cout << check[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
