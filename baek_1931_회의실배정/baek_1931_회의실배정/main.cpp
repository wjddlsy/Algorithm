//
//  main.cpp
//  baek_1931_회의실배정
//
//  Created by 윤정인 on 2018. 7. 27..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, begin, end;
    vector<pair<int, int>> order;
    
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> begin >> end;
        order.push_back(make_pair(end, begin));
    }
    
    sort(order.begin(), order.end());
    
    int earlist=0, selected=0;
    for(int i=0; i<order.size(); ++i){
        int meetingBegin=order[i].second, meetingEnd=order[i].first;
        
        if(earlist <= meetingBegin){
            earlist=meetingEnd;
            ++selected;
        }
    }
    std::cout << selected;
    return 0;
}
