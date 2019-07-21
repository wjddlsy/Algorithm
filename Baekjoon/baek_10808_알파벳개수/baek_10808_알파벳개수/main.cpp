//
//  main.cpp
//  baek_10808_알파벳개수
//
//  Created by 윤정인 on 07/10/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>
using namespace std;

int alpha[26]={0,};
int main(int argc, const char * argv[]) {
    char c;
    while(cin>>c){
        alpha[c-'a']++;
    }
    
    for(int i=0; i<26; ++i){
        cout<<alpha[i]<<" ";
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
