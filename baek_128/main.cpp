//
//  main.cpp
//  baek_128
//
//  Created by 윤정인 on 2018. 6. 6..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    multiset<string> ms;
    map<string, int> map;
    int N, M, count=0;
    string x;
    pair<std::map<string, int>::iterator, bool> ret;
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> x;
        ms.insert(x);
        ret=map.insert(pair<string, int>(x,1));
    }
    for(int i=0; i<M; ++i){
        cin >> x;
        ms.insert(x);
        ret=map.insert(pair<string, int>(x,1));
        if(ret.second==false){
            ret.first->second++;
            count++;
        }
    }
    cout << count << '\n';
    std::map<string, int>::iterator it;
    for(it=map.begin(); it!=map.end(); ++it){
        if(it->second==2)
            cout << it->first << '\n';
    }
    return 0;
}
