//
//  main.cpp
//  baek_2875_대회인턴
//
//  Created by 윤정인 on 2018. 7. 21..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int w, m, k;
    std::cin >> w >> m >> k;
    
    int wt=std::min(w/2, m);
    
    int r= w + m - 3 * wt;
    
    //1. r <= k  인 경우
    if (  r >= k )
        std::cout << wt;
    
    //2. r > k 인 경우
    else {
        int l= k - r;
        int result=wt - l /3  - 1 ;
        
        if (result<0)
            std::cout << 0;
        else
            std::cout << result;
        
    }
  
    std::cout << std::endl;
    std::cout << std::min({ w/2, m, (w+m-k)/3 });
    

    //std::cout << "Hello, World!\n";
    return 0;
}
