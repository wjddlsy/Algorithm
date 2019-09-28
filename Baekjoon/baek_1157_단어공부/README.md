# 단어 공부

| 시간 제한 | 메모리 제한 | 제출  | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ----- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 25622 | 8822 | 6941      | 34.992%   |

## 문제

알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

## 입력

첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

## 출력

첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

## 예제 입력 1 복사

```
Mississipi
```

## 예제 출력 1 복사

```
?
```

## 예제 입력 2 복사

```
zZa
```

## 예제 출력 2 복사

```
Z
```

## 예제 입력 3 복사

```
z
```

## 예제 출력 3 복사

```
Z
```

## 예제 입력 4 복사

```
baaa
```

## 예제 출력 4 복사

```
A
```



## 출처

- 문제를 만든 사람: [author5](https://www.acmicpc.net/user/author5)
- 데이터를 추가한 사람: [jh05013](https://www.acmicpc.net/user/jh05013)

# Solve

## 찾아본것

### MAP SORT

- MAP을 key 기준으로 sort 하고 싶다면

  ```c++
  map<int, int> m;
  vector<pair<int, int>> v;
  for (auto mm:m)
      v.emplace_back(make_pair(mm.first, mm.second));
  ```



## CODE

```C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <map>
using namespace std;


int main(int argc, const char * argv[]) {
    map<char, int> m;
    char s;
    while(cin>>s){
        m[toupper(s)]++;
    }
    
    vector<pair<int, char>> v;
    for(auto mm:m)
        v.emplace_back(make_pair(-mm.second,mm.first));
    
    sort(v.begin(), v.end());
    if(v[0].first==v[1].first)
        cout << "?";
    else
        cout << v[0].second;
    
    
}

```



