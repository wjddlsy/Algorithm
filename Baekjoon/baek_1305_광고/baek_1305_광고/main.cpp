//
//  main.cpp
//  baek_1305_광고
//
//  Created by 윤정인 on 30/09/2018.
//  Copyright © 2018 윤정인. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;
    
    vector<int> pi(m, 0);
    
    for (int i = 1; i< m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

//접미사 길이 출력인거가튼대
int main(int argc, const char * argv[]) {
    // insert code here..
    int L;
    string s;
    cin >> L >> s;
    vector<int> ret=getPi(s);
    int n=s.size();
    cout << n-ret[n-1];
    //std::cout << "Hello, World!\n";
    return 0;
}
