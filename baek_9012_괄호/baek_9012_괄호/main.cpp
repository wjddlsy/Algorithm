//
//  main.cpp
//  baek_9012_괄호
//
//  Created by 윤정인 on 2018. 7. 12..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
std::string isParen(std::string s){
    
    return "NO";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    char x;
    bool ret=true;
    std::string input;
    std::vector<char> stk;
    std::cin >> n;
    std::cin.get();
    for (int i=0; i<n; ++i){
        
        while(std::cin.get(x)){
            if (x=='\n')
                break;
            if (x=='(')
                stk.push_back(x);
            else if(x==')') {
                if (stk.empty()) {
                    stk.push_back('x');
                    ret=false;
                }
                stk.pop_back();
            }
        }
        
        if(stk.empty() && ret )
            std::cout << "YES" << std::endl;
        else {
            std::cout <<"NO" <<std::endl;
            stk.resize(0);
        }
        
        ret=true;
    }
    
    
    return 0;
}


