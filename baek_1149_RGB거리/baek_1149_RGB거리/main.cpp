//
//  main.cpp
//  baek_1149_RGB거리
//
//  Created by 윤정인 on 2018. 7. 2..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

int n, arr[1001][3], cache[1001][3];

int smallest(int x, int y, int z){
    return std::min(std::min(x, y), z);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin >> n;
    for(int j=1; j<=n; ++j){
        for (int i=0; i<3; ++i){
            std::cin >> arr[j][i];
        }
    }
    
    cache[0][0]=cache[1][0]=cache[2][0]=0;
    for(int i=1; i<=n; ++i){
        cache[i][0]=std::min(cache[i-1][1]+arr[i][0], cache[i-1][2]+arr[i][0]);
        cache[i][1]=std::min(cache[i-1][0]+arr[i][1], cache[i-1][2]+arr[i][1]);
        cache[i][2]=std::min(cache[i-1][0]+arr[i][2], cache[i-1][1]+arr[i][2]);
    }
    
    
    std::cout << smallest(cache[n][0], cache[n][1], cache[n][2]);
    
    return 0;
}
