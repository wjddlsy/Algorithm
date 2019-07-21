//
//  main.cpp
//  baek_9095
//
//  Created by 윤정인 on 2018. 7. 5..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <math.h>

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
int count(int n){
    int x=n/3, y, z, c=0;
    for (int i=x; i>=0; --i){
        y=(n-3*i)/2;
        for(int j=y; j>=0; --j){
            z = n- 3*i -2*j;
            c+=factorial(i+j+z) / (factorial(i)*factorial(j)*factorial(z));
        }
            
    }
    return c;
}

int count2(int n){
    int result[12];
    result[1]=1;
    result[2]=2;
    result[3]=4;
    for (int i=4; i<11; ++i){
        result[i]=result[i-3]+result[i-2]+result[i-1];
    }
    
    return result[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, input;
    std::cin >> n;
    
    for(int i=0; i<n; ++i){
        std::cin >> input;
        std::cout << count(input) <<std::endl;
        std::cout << count2(input) << std::endl;
    }

    return 0;
}
