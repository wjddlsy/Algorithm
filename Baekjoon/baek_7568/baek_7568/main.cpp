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
#include <utility>

using namespace std;

#define N 9
int sum=0;
vector<pair<int, int>> input;
vector<int> result;


void pick(int n, vector<int>& picked, int toPick){
    // 기저 사례: 더 고를 원소가 없을 때
    if (toPick==0) {
        if(input[picked[0]].first > input[picked[1]].first && input[picked[0]].second > input[picked[1]].second)
            result[picked[1]]++;
        else if(input[picked[0]].first < input[picked[1]].first && input[picked[0]].second < input[picked[1]].second)
            result[picked[0]]++;
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
    int n, x, y;
    vector<int> picked;
    cin >> n;
    result.resize(n);
    for(int i=0; i<n; i++){
        cin >> x >> y;
        input.push_back(make_pair(x, y));
    }
    pick(n, picked, 2);
    
    vector<int> rank(n, 1);
    
    for(int i=0; i<n; i++){
        rank[i]=1;
        for(int j=0; j<n; j++){
            if(result[i]>result[j])
                rank[i]++;
        }
    }
    
    for (int i=0; i<n; i++){
        cout << result[i]+1 << " ";
    }
    
    
    
    
    return 0;
}


