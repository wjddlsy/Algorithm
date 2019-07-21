//
//  main.cpp
//  baek_11047_동전0
//
//  Created by 윤정인 on 2018. 7. 26..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> v;
    int N, K, x, ret=0;
    cin >> N >> K ;
    
    for (int i=0; i<N; ++i){
        cin >> x;
        if (x>K){
            N=i;
            break;
        }
        v.push_back(x);
    }
    
    
    for(int i=N; i>=1; i--){
        ret+=K / v[i-1];
        K%=v[i-1];
        
    }
    std::cout << ret;
    return 0;
}
