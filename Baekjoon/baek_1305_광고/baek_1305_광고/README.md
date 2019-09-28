# 광고

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 1057 | 463  | 377       | 49.153%   |

## 문제

세준이는 길 한가운데에서 전광판을 쳐다보고 있었다. 전광판에는 광고가 영어로 광고가 흘러나오고 있었다. 한참을 전광판을 쳐다본 세준이는 이 광고가 의미하는 것이 무엇인지 궁금해지기 시작했다.

전광판에는 같은 내용의 문구가 무한히 반복되어 나온다. 또, 전광판의 크기는 전광판에서 한번에 보이는 최대 문자수를 나타낸다. 만약 전광판의 크기가 L이라면, 한번에 L개의 문자를 표시할 수 있는 것이다.

광고업자는 최대한의 광고효과를 내기 위해서 길이가 N인 광고를 무한히 붙여서 광고한다.

예를 들어, 광고 업자 백은진이 광고하고 싶은 내용이 aaba 이고, 전광판의 크기가 6이라면 맨 처음에 보이는 내용은 aabaaa 이다. 시간이 1초가 지날 때마다, 문자는 한 칸씩 옆으로 이동한다. 따라서 처음에 aabaaa가 보였으면 그 다음에는 abaaab가 보인다. 그 다음에는 baaaba가 보인다.

세준이가 어느 순간 전광판을 쳐다봤을 때, 그 때 쓰여 있는 문자가 입력으로 주어졌을 때, 가능한 광고의 길이중 가장 짧은 것을 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에 광고판의 크기 L이 주어지고, 둘째 줄에 현재 광고판에 보이는 문자열이 주어진다. L은 백만보다 작거나 같은 자연수이다.

## 출력

첫째 줄에 가능한 광고의 길이중 가장 짧은 것의 길이를 출력한다.

## 예제 입력 1 복사

```
5
aaaaa
```

## 예제 출력 1 복사

```
1
```



## 출처

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 데이터를 추가한 사람: [kkddgg1001](https://www.acmicpc.net/user/kkddgg1001)
- 문제의 오타를 찾은 사람: [sgc109](https://www.acmicpc.net/user/sgc109)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/1305#)



# Solve

## Code

```C++
//
//  main.cpp
//  baek_1305_광고
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

```





