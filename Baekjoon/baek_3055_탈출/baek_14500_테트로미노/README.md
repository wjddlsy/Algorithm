# 테트로미노

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 512 MB      | 9043 | 2985 | 1982      | 31.376%   |

## 문제

폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

- 정사각형은 서로 겹치면 안된다.
- 도형은 모두 연결되어 있어야 한다.
- 정사각형의 꼭짓점끼리 연결되어 있어야 한다. 즉, 변과 꼭짓점이 맞닿아있으면 안된다.

정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.

[![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14500/1.png)](https://commons.wikimedia.org/wiki/File:All_5_free_tetrominoes.svg)

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

## 입력

첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

## 출력

첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

## 예제 입력 1 복사

```
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1
```

## 예제 출력 1 복사

```
19
```

## 예제 입력 2 복사

```
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
```

## 예제 출력 2 복사

```
20
```

## 예제 입력 3 복사

```
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
```

## 예제 출력 3 복사

```
7
```



## 출처

- 문제를 만든 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 데이터를 추가한 사람: [stack](https://www.acmicpc.net/user/stack) [vjerksen](https://www.acmicpc.net/user/vjerksen)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/14500#)



# Solve

## 생각해보기

- 입력 조건

  $4 \le N, N \le 500 $

  —> 별로 안큼 

- 다 돌리면 될 것 같음

- 테트로미노를 어떻게 표현할지 



## 테트로미노 표현하기

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14500/1.png)



## Code

```c++

#include <iostream>
#include <vector>
using namespace std;

#define MAX_NM 500

int N, M;
int board[MAX_NM][MAX_NM];
int MAX=0;

bool isRange(int y, int x){
    if(y>=N || y<0 || x>=M || x<0)
        return false;
    return true;
}

void straight(){
    for (int i=0; i<=N-4; ++i){
        for (int j=0; j<=M-4; ++j){
            for (int dx=0; dx<4; ++dx){
                MAX=std::max(MAX,board[i][j+dx] + board[i+1][j+dx] + board[i+2][j+dx] + board[i+3][j+dx]);
            }
            for (int dy=0; dy<4; ++dy){
                MAX=std::max(MAX, board[i+dy][j] + board[i+dy][j+1] + board[i+dy][j+2] + board[i+dy][j+3]);
            }
            
        }
    }
}

void square(){
    for(int i=0; i<=N-2; ++i){
        for (int j=0; j<=M-2; ++j){
            MAX=std::max(MAX, board[i][j]+board[i+1][j]+board[i][j+1] + board[i+1][j+1]);
        }
    }
}

void six(){
    int sum=0;
    for(int i=0; i<=N-3; ++i){
        for(int j=0; j<=M-2; ++j){
            sum =0;
            for (int dx=0; dx<2; ++dx){
                for (int dy=0; dy<3; ++dy)
                    sum += board[i+dy][j+dx];
            }
            // 1. L자 -> 4가지
            MAX=std::max(MAX, sum - board[i][j]-board[i+1][j]);
            MAX=std::max(MAX, sum - board[i][j+1]-board[i+1][j+1]);
            MAX=std::max(MAX, sum - board[i+1][j]-board[i+2][j]);
            MAX=std::max(MAX, sum - board[i+1][j+1]-board[i+2][j+1]);
            
            // 2. 티자 -> 2가지
            MAX=std::max(MAX, sum - board[i][j+1]- board[i+2][j+1]);
            MAX=std::max(MAX, sum - board[i][j] - board[i+2][j]);
            
            // 3. s자 -> 2가지
            MAX=std::max(MAX, sum -board[i][j+1]-board[i+2][j]);
            MAX=std::max(MAX, sum - board[i][j]-board[i+2][j+1]);
            
        }
    }
    
    for(int i=0; i<=N-2; ++i){
        for(int j=0; j<=M-3; ++j){
            sum =0;
            for (int dx=0; dx<3; ++dx){
                for (int dy=0; dy<2; ++dy)
                    sum += board[i+dy][j+dx];
            }
            // 1. L자 -> 4가지
            MAX=std::max(MAX, sum - board[i][j]-board[i][j+1]);
            MAX=std::max(MAX, sum - board[i][j+1]-board[i][j+2]);
            MAX=std::max(MAX, sum - board[i+1][j]-board[i+1][j+1]);
            MAX=std::max(MAX, sum - board[i+1][j+1]-board[i+1][j+2]);
            
            // 2. 티자 -> 2가지
            MAX=std::max(MAX, sum - board[i][j]- board[i][j+2]);
            MAX=std::max(MAX, sum - board[i+1][j] - board[i+1][j+2]);
            
            // 3. s자 -> 2가지
            MAX=std::max(MAX, sum - board[i+1][j]-board[i][j+2]);
            MAX=std::max(MAX, sum - board[i][j]-board[i+1][j+2]);
            
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        for (int j=0; j<M; ++j)
            cin >> board[i][j];
    }
    straight();
    square();
    six();
    
    cout << MAX;
    
    return 0;
}

```



## ...

- 실수해서 디버깅하다가 애먹었다 ㅠ ㅠ 



