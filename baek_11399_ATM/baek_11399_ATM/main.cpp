//
//  main.cpp
//  baek_11399_ATM
//
//  Created by 윤정인 on 2018. 7. 21..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, input;
    std::vector<int> v;
    std::cin >> n;
    
    for(int i=0; i<n; ++i){
        std::cin >> input;
        v.push_back(input);
    }
    
    std::sort(v.begin(), v.end());
    int sum=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<=i; ++j)
            sum += v[j];
    }
    std::cout << sum;
    return 0;
}
