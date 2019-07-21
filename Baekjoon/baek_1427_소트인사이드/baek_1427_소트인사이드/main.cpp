//
//  main.cpp
//  baek_1427_소트인사이드
//
//  Created by 윤정인 on 01/10/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    char c;
    vector<char> v;
    while(cin>>c){
        v.push_back(c);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(auto vv:v){
        cout<<vv;
    }
    
    //std::cout << "Hello, World!\n";
    return 0;
}
ddd

