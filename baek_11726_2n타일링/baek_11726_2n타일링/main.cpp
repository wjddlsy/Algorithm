//
//  main.cpp
//  baek_11726_2n타일링
//
//  Created by 윤정인 on 2018. 7. 6..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int arr[1001];
    std::cin >> n;
    arr[1]=1; arr[2]=2;
    for(int i=3; i<=n; ++i){
        arr[i]=arr[i-1]+arr[i-2];
    }
    
    std::cout << arr[n];
    
    //std::cout << "Hello, World!\n";
    return 0;
}
