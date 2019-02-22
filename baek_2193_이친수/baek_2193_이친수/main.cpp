//
//  main.cpp
//  baek_2193_이친수
//
//  Created by 윤정인 on 2018. 7. 7..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

long long  cache[91];
int main(int argc, const char * argv[]) {
    // insert code here...
    long long  n;
    std::cin >> n;
    
    cache[1]=cache[2]=1;
    for (int i=3; i<=n; ++i){
        cache[i]=cache[i-1]+cache[i-2];
    }
    std::cout << cache[n];
    //std::cout << "Hello, World!\n";
    return 0;
}
