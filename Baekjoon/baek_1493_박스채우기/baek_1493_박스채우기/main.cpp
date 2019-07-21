//
//  main.cpp
//  baek_1493_박스채우기
//
//  Created by 윤정인 on 2018. 9. 25..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
using namespace std;
int l, w, h, N;

int cube[20];
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> l >> w >> h;
    cin >> N;
    // 1. i <= logl, w, h
    int a, b;
    while(N--){
        cin >> a >> b;
        cube[a] = b ;
    }
    
    // 큰거먼저 채워야하지 않을까요
    // 일단 분리햅...
    // 4 4 8 이면
    // 4 4 4 / 4 4 4
    
    // 4 4 7
    // 4 4 4 / 4 4 3 / 4 4 2 / 4 4 1 /
    // 5 8 9
    
    int m = min(l, min(w, h));
    int m_n = log

    std::cout << "Hello, World!\n";
    return 0;
}
