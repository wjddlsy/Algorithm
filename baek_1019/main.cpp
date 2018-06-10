//
//  main.cpp
//  baek_1019
//
//  Created by 윤정인 on 2018. 6. 8..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
long long arr[10];
int result=0;

void counting(std::string str){
    int n1=str[0]-'0';
    int size=str.size();
    
    if(str.size()==1){
        for(int i=0; i<=str[0]-'0'; ++i){
            arr[i]++;
        }
        return;
    }
    std::string new_input;
    
    new_input=str;
    new_input.erase(new_input.begin());
    arr[str[0]-'0']+=std::stoi(new_input)+1;
    
    counting(new_input);
    
    std::string new_input2=std::to_string((int)pow(10, str.size()-1)-1);
    for(int i=0; i<n1; ++i){
        arr[i]+=pow(10, size-1);
        for(int j=0; j<10; ++j){
            arr[j]+=new_input2.size()*pow(10, new_input2.size()-1);
        }
    }
    
    
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::ios_base::sync_with_stdio(false);
    int n;
    std::string str;
    std::cin >> n;
    
    str=std::to_string(n);
    counting(str);
    
    std::string zero;
    for(int i=0; i<str.size(); ++i){
        zero+="1";
    }
    arr[0]-=std::stoi(zero);
    for(int i=0; i<10; ++i){
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
