//
//  main.cpp
//  baek_11656_접미사배열
//
//  Created by 윤정인 on 2018. 7. 10..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string s,t ;
    std::cin >> s;
    std::vector<std::string> ret;
    for (int i=0; i<s.size(); ++i){
        ret.push_back(s.substr(i, std::string::npos));
    }
    
    std::sort(ret.begin(), ret.end());
    
    for (int i=0; i<ret.size(); ++i)
        std::cout << ret.at(i) <<std::endl;
    return 0;
}
