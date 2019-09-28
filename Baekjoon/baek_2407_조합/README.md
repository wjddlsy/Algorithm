# 2407 조합 실패

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 7953 | 1876 | 1602      | 32.220%   |

## 문제

nCm을 출력한다.

## 입력

n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)

## 출력

nCm을 출력한다.

## 예제 입력 1 복사

```
100 6
```

## 예제 출력 1 복사

```
1192052400
```



## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/2407#)



# Solve

## Idea

### Big Integer 

```c++
string bigIntegerAdd(string a, string b){
    long long sum=0;
    string ret;
    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()){
            sum+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum+=b.back()-'0';
            b.pop_back();
        }
        ret.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
```

## Code 

```C++
#include <iostream>
#include <algorithm>
using namespace std;

string cache[101][101];

string bigIntegerAdd(string a, string b){
    long long sum=0;
    string ret;
    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()){
            sum+=a.back()-'0';
            a.pop_back();
        }
        if(!b.empty()){
            sum+=b.back()-'0';
            b.pop_back();
        }
        ret.push_back((sum%10)+'0');
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string solve(int n, int m){
    if(n==m || m==0)
        return "1";
    string &ret=cache[n][m];
    if(ret!="")
        return ret;
    return ret=bigIntegerAdd(solve(n-1, m-1), solve(n-1,m));

}
int main() {
    int n, m;
    cin>>n>>m;
    std::cout << solve(n, m)<<endl;
    return 0;
}
```

