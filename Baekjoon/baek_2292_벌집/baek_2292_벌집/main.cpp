//
//  main.cpp
//  baek_2292_벌집
//
//  Created by 윤정인 on 01/10/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    long long n,i;
    cin >> n;
    for(i=1; i<100000; i++){
        if(3*i*i-3*i+1>=n) break;
        
    }
    cout << i;
    return 0;
}
