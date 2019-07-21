//
//  main.cpp
//  baek_9465_스티커
//
//  Created by 윤정인 on 2018. 7. 7..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

int arr[2][100];
int cache[100][3];
int maxScore(int n){
    int ret;
    cache[1][0]=0;
    cache[1][1]=arr[0][1];
    cache[1][2]=arr[1][1];
    
    for (int i=2; i<=n; ++i){
        cache[i][0]=std::max(cache[i-1][1], cache[i-1][2]);
        cache[i][1]=std::max(cache[i-1][2], cache[i-1][0])+arr[0][i];
        cache[i][2]=std::max(cache[i-1][1], cache[i-1][0])+arr[1][i];
    }
    return std::max(cache[n][1],cache[n][2]);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int T, n, input;
    std::cin >> T;
    for (int i=0; i<T; ++i){
        std::cin >>n;
        for (int j=0; j<2; ++j){
            for (int k=1; k<=n; ++k){
                std::cin >> arr[j][k];
            }
        }
        std::cout << maxScore(n) << std::endl;
        
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
