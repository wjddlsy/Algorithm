# 현상금 사냥꾼 김정은 

> 출처:[백준 10272](https://www.acmicpc.net/problem/10272)

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 256 MB      | 440  | 204  | 133       | 42.628%   |

## 문제

현상금 사냥꾼인 정은이는 지금 범죄자를 쫓고 있는 중이다. 정은이는 갈치 II호를 사용해서 우주를 돌아다니면서 조사를 하는데, 2차원 유클리드 우주에 존재하는 N개의 다른 행성을 모두 방문한 다음 시작위치로 돌아와야 한다. 시작위치는 가장 왼쪽의 행성(with the lowest x-coordinate)이고, 정은이는 모든 행성을 방문해서 조사해야 한다. 하지만 가난하지만 사치스러운, 정은이는 돈을 아껴서 비싼 소고기를 먹기 위해서, 최소한의 거리로 행성을 모두 방문하기 원한다.

추가적으로 그는 CTP라는 범죄조직을 쫓고 있는데, 그들한테서 들키지 않도록, 정은이는 조사할때, x의 좌표가 오름차순인 순서대로 행성을 방문하고, 가장 오른쪽(with the largest x-coordinate)에 있는 행성을 방문하면, 다시 내림차순 순서대로 시작위치로 돌아와야 한다.

## 입력

입력은 테스트케이스 T (1 ≤ T ≤ 100)가 주어진다. 각각의 테스트 케이스는 여행에서 방문해야 할 장소의 수 N (2 ≤ N ≤ 512)과 각각의 좌표 (0 ≤ x, y ≤ 5000)가 주어진다. 입력으로 주어지는 x좌표는 중복되지 않으며, 증가하는 순서대로 주어진다.

## 출력

각각의 테스트케이스마다 여행의 최단거리를 출력한다. 오차는 최대 10-2까지 허용된다.

## 예제 입력 1 복사

```
2
5
0 1
1 2
2 0
3 2
4 1
3
100 1
200 1
300 1
```

## 예제 출력 1 복사

```
9.300563079746
400
```



## 출처

[ACM-ICPC ](https://www.acmicpc.net/category/1)> [Regionals ](https://www.acmicpc.net/category/7)> [Europe ](https://www.acmicpc.net/category/10)> [Northwestern European Regional Contest ](https://www.acmicpc.net/category/15)> [German Collegiate Programming Contest ](https://www.acmicpc.net/category/47)> [GCPC 2014](https://www.acmicpc.net/category/detail/1285) C번

- 문제를 번역한 사람: [hakgb11](https://www.acmicpc.net/user/hakgb11)
- 문제의 오타를 찾은 사람: [orange4glace](https://www.acmicpc.net/user/orange4glace) [zych1751](https://www.acmicpc.net/user/zych1751)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/10272#)



## Solve

### Bitonic Tour

- TSP의 특수한 경우 중 하나



### 유사문제

- 경찰차 (몇번이더라)
