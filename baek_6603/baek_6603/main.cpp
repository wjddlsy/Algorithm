//
//  main.cpp
//  baek_2309
//
//  Created by 윤정인 on 2018. 5. 29..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 9
int sum=0;
vector<int> input;


void pick(int n, vector<int>& picked, int toPick){
    // 기저 사례: 더 고를 원소가 없을 때
    if (toPick==0) {
        for (int i=0; i<6; i++){
            cout << input.at(picked.at(i)) << " ";
        }
        cout << endl;
        return;
    }
    
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    
    for (int next=smallest; next<n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // 9C2 = sum - 100; 인 것 찾 기
    
    // 입출력
    int n, in;
    vector<int> picked;
    while(true) {
        cin >> n;
        if(n==0)
            break;
        for(int i=0; i<n; ++i){
            cin >> in;
            input.push_back(in);
        }
        pick(n, picked, 6);
        input.clear();
        picked.clear();
    }
    
    return 0;
}

