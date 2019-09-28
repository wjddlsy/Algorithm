# 그룹 단어 체커

| 시간 제한 | 메모리 제한 | 제출  | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ----- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 11410 | 5604 | 4946      | 50.650%   |

## 문제

그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

## 출력

첫째 줄에 그룹 단어의 개수를 출력한다.

## 예제 입력 1 복사

```
3
happy
new
year
```

## 예제 출력 1 복사

```
3
```

## 예제 입력 2 복사

```
4
aba
abab
abcabc
a
```

## 예제 출력 2 복사

```
1
```



## 출처

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 데이터를 추가한 사람: [jh05013](https://www.acmicpc.net/user/jh05013)
- 문제의 오타를 찾은 사람: [joonas](https://www.acmicpc.net/user/joonas)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/1316#)



# Solve

## 생각해보기

- 이전에 나온적이 있고
- 내 앞에 문자랑 지금 문자랑 같지 않다면
- 답이아님

## Code

```c++
#include <iostream>
using namespace std;


bool a[26];
int main(int argc, const char * argv[]) {
    string s;
    int n, answer=0;
    cin >> n;
    while(n--){
        cin >>s;
        fill_n(a,26,false);
        a[s[0]-'a']=true;
        for(int i=1; i<s.size(); ++i){
            if(a[s[i]-'a'] && s[i-1]!=s[i]){
                answer--;
                break;
            }
            a[s[i]-'a']=true;
        }
        answer++;
    }
    cout<<answer;
}
```

## 음

뭔가 지저분해!