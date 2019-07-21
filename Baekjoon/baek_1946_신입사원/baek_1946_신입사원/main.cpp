//
//  main.cpp
//  baek_1946_신입사원
//
//  Created by 윤정인 on 2018. 8. 6..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int, int>> order;
    
    ios_base::sync_with_stdio(false);
    
    int T, N, a, b, min, ret=0;
    cin >> T ;
    
    for (int i=0; i<T; ++i){
        cin >> N;
        for (int j=0; j<N; ++j){
            cin >> a >> b ;
            order.push_back(make_pair(a, b));
        }
        
        sort(order.begin(), order.end());
        
        min = N + 1;
        
        for(int k=0; k<N; ++k){
            if (order[k].second > min)
                continue;
            ret ++;
            min = order[k].second;
        }
        std::cout <<  ret << endl;
        ret = 0;
        order.clear();
    }
    
    return 0;
}
