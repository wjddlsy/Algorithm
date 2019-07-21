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
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, input;
    std::cin >> n;
    
    for(int i=0; i<n; ++i){
        std::cin >> input;
        std::cout << count(input) <<std::endl;
    }

    return 0;
}
