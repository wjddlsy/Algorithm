//
//  main.cpp
//  baek_2667
//
//  Created by 윤정인 on 2018. 6. 7..
//  Copyright © 2018년 윤정인. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, a=0, count=0;
int check[25][25];

bool inRange(int y, int x){
    if (x<0 || x>=n || y<0 || y>=n )
        return false;
    return true;
}
bool isChecked(int y, int x){
    for(int direction=0; direction<4; ++direction){
        int nextY=y+dy[direction], nextX=x+dx[direction];
        if(!check[y][x])
            return false;
    }
    return true;
}
void count_a(std::vector<std::vector<int>> &arr, int y, int x){
    //기저사례 1: 시작위치가 범위 밖인 경우
    if(!inRange(y, x))
        return;
    //기저사례 2: 0인 경우
    if(!arr[y][x])
        return;
    //기저사례 3: 성공
    if(check[y][x])
        return;
    else {
        check[y][x]=true;
        count++;
    }
    for(int direction=0; direction<4; ++direction){
        int nextY=y+dy[direction], nextX=x+dx[direction];
        //count++;
        count_a(arr, nextY, nextX);
    }
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string s;
    std::cin >> n;
    std::vector<std::vector<int>> arr(n);
    for(int i=0; i<n; ++i){
        std::cin >> s;
        for(int j=0; j<n; ++j)
            arr[i].push_back(s[j]-'0');
    }
    
    std::ios_base::sync_with_stdio(false);
    
    int c=0;
    std::vector<int> result;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(arr[j][i] && !check[j][i]){
                c++;
                count_a(arr, j, i);
                result.push_back(count);
            }
            count=0;
        }
    }
    sort(result.begin(), result.end());
    std::cout << c << std::endl;
    for(int i=0; i<result.size(); ++i){
        std::cout << result[i] << std::endl;
    }
    return 0;
}
