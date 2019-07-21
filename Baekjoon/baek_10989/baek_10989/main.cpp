//
//  main.cpp
//  baek_10989
//
//  Created by 윤정인 on 2018. 6. 5..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::ios_base::sync_with_stdio(false);
    int N, x, max=0;
    map<int, int> map;
    
    cin >> N;
    
    pair< std::map<int, int>::iterator, bool > ret;
    for(int i=0; i<N; ++i){
        cin >> x;
        ret=map.insert(pair<int, int>(x, 1));
        if(ret.second==false)
            ret.first->second++;
    }
    
    std::map<int, int>::iterator it;
    for(it=map.begin(); it!=map.end(); ++it){
        for(int i=0; i<it->second; ++i)
            cout << it->first << endl;
    }
    
    return 0;
}
