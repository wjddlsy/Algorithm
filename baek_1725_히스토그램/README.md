# 1725

https://www.acmicpc.net/problem/1725

## 문제

히스토그램에 대해서 알고 있는가? 히스토그램은 아래와 같은 막대그래프를 말한다.

![img](https://www.acmicpc.net/JudgeOnline/upload/201006/hist.PNG)

각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 위 그림의 경우 높이가 각각 2 1 4 5 1 3 3이다.

이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 한다. 아래 그림의 빗금 친 부분이 그 예이다. 이 직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.

![img](https://www.acmicpc.net/JudgeOnline/upload/201006/histo.PNG)

주어진 히스토그램에 대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오.

## 입력

첫 행에는 N (1 <= N <= 100,000) 이 주어진다. N은 히스토그램의 가로 칸의 수이다. 다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다.

## 출력

첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다.

## 예제 입력 1 복사

```
7
2
1
4
5
1
3
3
```

## 예제 출력 1 복사

```
8
```





## Solve

알고리즘해결전략 - 울타리 잘라내기 와 동일한 문제 

### 1. Brute force 

- 무식하게 풀 수 있을까?
  - O(n^2) !... 

```c++
int bruteForce(const std::vector<int>& h){
    int ret=0;
    int N=(int)h.size();
    for (int left=0; left<N; ++left){
        int minheight=h[left];
        for (int right=left; right<N; ++right) {
            minheight= std::min(minheight, h[right]);
            ret = std::max(ret, (right-left + 1) * minheight);
        }
    }
    return ret;
    
}
```



## 2. 분할정복

- 가장 큰 직사각형을 왼쪽 부분 문제에서만 잘라낼 수 있다. 
- 가장 큰 직사각형을 오른쪽 부분 문제에서만 잘라낼 수 있다. 
- 가장 큰 직사각형은 왼쪽 부분 문제와 오른쪽 부분 문제에 걸쳐 있다. 



### 양쪽 부분 문제에 걸친 경우

- 이러한 직사각형은 반드시 부분 문제 경계에 있는 두 판자를 포함한다
- 항상 사각형의 높이를 최대화하는 방향으로 확장 

