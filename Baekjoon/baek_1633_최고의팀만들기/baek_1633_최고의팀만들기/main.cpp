//
//  main.cpp
//  baek_1633_최고의팀만들기
//
//  Created by 윤정인 on 2018. 7. 7..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>

int main(int argc, const char * argv[]) {
    // insert code here...
    int ret, w, b;
    int white[15], black[15];
    std::map<int, int> m;
    for (int i=0; i<30; ++i){
        std::cin >> w >> b;
        m.insert(std::make_pair(w, i));
        m.insert(std::make_pair(b, -i));
    }
    std::cout << "Hello, World!\n";
    return 0;
}
