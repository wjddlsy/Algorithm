# 15686 치킨 배달

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 512 MB      | 3272 | 1314 | 817       | 37.754%   |

## 문제

크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "**치킨 거리**"라는 말을 주로 사용한다. **치킨 거리**는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 **치킨 거리**를 가지고 있다. **도시의 치킨 거리**는 모든 집의 **치킨 거리**의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

예를 들어, 아래와 같은 지도를 갖는 도시를 살펴보자.

```
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
```

0은 빈 칸, 1은 집, 2는 치킨집이다.

(2, 1)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |2-1| + |1-2| = 2, (5, 5)에 있는 치킨집과의 거리는 |2-5| + |1-5| = 7이다. 따라서, (2, 1)에 있는 집의 치킨 거리는 2이다.

(5, 4)에 있는 집과 (1, 2)에 있는 치킨집과의 거리는 |5-1| + |4-2| = 6, (5, 5)에 있는 치킨집과의 거리는 |5-5| + |4-5| = 1이다. 따라서, (5, 4)에 있는 집의 치킨 거리는 1이다.

이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, **도시의 치킨 거리**가 가장 작게 될지 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

## 출력

첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.

## 예제 입력 1 복사

```
5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2
```

## 예제 출력 1 복사

```
5
```

## 예제 입력 2 복사

```
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2
```

## 예제 출력 2 복사

```
10
```

## 예제 입력 3 복사

```
5 1
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
```

## 예제 출력 3 복사

```
11
```

## 예제 입력 4 복사

```
5 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
```

## 예제 출력 4 복사

```
32
```



## 출처

- 문제를 만든 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 문제의 오타를 찾은 사람: [chaeeun218](https://www.acmicpc.net/user/chaeeun218) [wlsgussla123](https://www.acmicpc.net/user/wlsgussla123)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/15686#)



# Solve

## 찾아본 것

### Combination

```C++
void pick(int n, vector<int> &picked, int toPick){
    if(toPick==0) {
        cal(picked);
        return;
    }
    
    int smallest = picked.empty() ? 0: picked.back()+1;
    
    for(int next = smallest; next<n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
    
    
}
```



## 생각

1. 치킨 집 중 M개를 고른당
2. 일일히 돌려본당 



## Code

```C++
#include <iostream>
#include <vector>
using namespace std;

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int N, M, sum = 0, ret=987654321;
int board[50][50];
vector<pair<int,int>> chicken;
vector<pair<int, int>> home;

void cal(vector<int> picked){
    sum = 0;
    for(int i=0; i<home.size(); ++i){
        int min = 987654321;
        for(int j=0; j<picked.size(); ++j){
            min=std::min(min, dist(home[i].first, home[i].second, chicken[picked[j]].first, chicken[picked[j]].second));
        }
        sum += min;
    }
    
    ret=std::min(ret, sum);

}
void pick(int n, vector<int> &picked, int toPick){
    if(toPick==0) {
        cal(picked);
        return;
    }
    
    int smallest = picked.empty() ? 0: picked.back()+1;
    
    for(int next = smallest; next<n; ++next){
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
            if(board[i][j]==2)
                chicken.push_back({i,j});
            else if(board[i][j]==1)
                home.push_back({i,j});
        }
    }
    
    int cn = chicken.size();
    vector<int> picked;
    pick(cn, picked,M);
    
    cout << ret;
    
   // std::cout << "Hello, World!\n";
    return 0;
}
```



