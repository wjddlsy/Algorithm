# 드래곤 커브 성공

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 512 MB      | 3140 | 1610 | 1116      | 49.888%   |

## 문제

드래곤 커브는 다음과 같은 세 가지 속성으로 이루어져 있으며, 이차원 좌표 평면 위에서 정의된다. 좌표 평면의 x축은 → 방향, y축은 ↓ 방향이다.

1. 시작 점
2. 시작 방향
3. 세대

0세대 드래곤 커브는 아래 그림과 같은 길이가 1인 선분이다. 아래 그림은 (0, 0)에서 시작하고, 시작 방향은 오른쪽인 0세대 드래곤 커브이다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15685/1.png)

1세대 드래곤 커브는 0세대 드래곤 커브를 끝 점을 기준으로 시계 방향으로 90도 회전시킨 다음 0세대 드래곤 커브의 끝 점에 붙인 것이다. 끝 점이란 시작 점에서 선분을 타고 이동했을 때, 가장 먼 거리에 있는 점을 의미한다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15685/2.png)

2세대 드래곤 커브도 1세대를 만든 방법을 이용해서 만들 수 있다. (파란색 선분은 새로 추가된 선분을 나타낸다)

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15685/3.png)

3세대 드래곤 커브도 2세대 드래곤 커브를 이용해 만들 수 있다. 아래 그림은 3세대 드래곤 커브이다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15685/4.png)

즉, K(K > 1)세대 드래곤 커브는 K-1세대 드래곤 커브를 끝 점을 기준으로 90도 시계 방향 회전 시킨 다음, 그것을 끝 점이 붙인 것이다.

크기가 100×100인 격자 위에 드래곤 커브가 N개 있다. 이때, 크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수를 구하는 프로그램을 작성하시오. 격자의 좌표는 (x, y)로 나타내며, 0 ≤ x ≤ 100, 0 ≤ y ≤ 100만 유효한 좌표이다.

## 입력

첫째 줄에 드래곤 커브의 개수 N(1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 드래곤 커브의 정보가 주어진다. 드래곤 커브의 정보는 네 정수 x, y, d, g로 이루어져 있다. x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대이다. (0 ≤ x, y ≤ 100, 0 ≤ d ≤ 3, 0 ≤ g ≤ 10)

입력으로 주어지는 드래곤 커브는 격자 밖으로 벗어나지 않는다. 드래곤 커브는 서로 겹칠 수 있다.

방향은 0, 1, 2, 3 중 하나이고, 다음을 의미한다.

- 0: x좌표가 증가하는 방향 (→)
- 1: y좌표가 감소하는 방향 (↑)
- 2: x좌표가 감소하는 방향 (←)
- 3: y좌표가 증가하는 방향 (↓)

## 출력

첫째 줄에 크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 출력한다.

## 예제 입력 1 복사

```
3
3 3 0 1
4 2 1 3
4 2 2 1
```

## 예제 출력 1 복사

```
4
```

## 예제 입력 2 복사

```
4
3 3 0 1
4 2 1 3
4 2 2 1
2 7 3 4
```

## 예제 출력 2 복사

```
11
```

## 예제 입력 3 복사

```
10
5 5 0 0
5 6 0 0
5 7 0 0
5 8 0 0
5 9 0 0
6 5 0 0
6 6 0 0
6 7 0 0
6 8 0 0
6 9 0 0
```

## 예제 출력 3 복사

```
8
```

## 예제 입력 4 복사

```
4
50 50 0 10
50 50 1 10
50 50 2 10
50 50 3 10
```

## 예제 출력 4 복사

```
1992
```

## 힌트

| ![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15685/ex1.png) | ![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15685/ex2.png) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 예제 1                                                       | 예제 2                                                       |

## 출처

- 문제를 만든 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)

## 알고리즘 분류

- [시뮬레이션](https://www.acmicpc.net/problem/tag/%EC%8B%9C%EB%AE%AC%EB%A0%88%EC%9D%B4%EC%85%98)

## 메모

# Solve

## Think

- 드래곤 커브 만들기 
- 드래곤 커브 규칙을 못찾겠다. 



## Code

> 못찾겠어서 인터넷에 찾아봤다. 
> 다들 똑똑한가보다 
>
> 나만 뻘짓했어

```c++

#include <iostream>
#include <vector>
using namespace std;

bool board[101][101];

int dx[4]={1, 0, -1, 0}, dy[4]={0,-1,0,1};

vector<int> dir;
void dragon(int x, int y, int d, int g ){
    board[y][x]=true;
    for(int i=0; i<g; ++i){
        int n = dir.size();
        for(int i=n-1; i>=0; --i){
            dir.push_back((dir[i]+1)%4);
        }
    }
    
    for(int i=0; i<dir.size(); ++i){
        x += dx[dir[i]];
        y += dy[dir[i]];
        board[y][x] = true;
        
    }
   
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, x, y, d, g;
    
    cin >> N;
    
    vector<pair<int, int>> point;
    while(N--){
        cin >> x >> y >> d >> g;
        dir.clear();
        dir.push_back(d);
        dragon(x, y, d, g);
    }
    
    int answer=0;
    
    for(int i=0; i<=99; ++i){
        for(int j=0; j<=99; ++j){
                if(board[i][j] & board[i+1][j] & board[i+1][j+1] & board[i][j+1])
                    answer++;
            
        }
    }
    
    cout << answer;
    //std::cout << "Hello, World!\n";
    return 0;
}

```



> 백준님 코드

```c++
#include <algorithm>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

vector<int> curve(int x, int y, int dir, int gen){
    vector<int> ans = {dir};
    for(int g=1; g<=gen; ++g){
        vector<int> temp(ans);
        reverse(temp.begin(), temp.end());
        for(int &i:temp) {
            i=(i+1)%4; // 반시계 방향 회전! 
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x, y, dir, gen; //시작점, 방향, 커브 
        cin >> y >> x >> dir >> gen;
        vector<int> dirs=curve(x,y,dir,gen);
        c[x][y]=true;
        for(int d:dirs){
            x+=dx[d];
            y+=dy[d];
            c[x][y]=true;
        }
    }
    int ans=0;
    for(int i=0; i<=99; ++i){
        for(int j=0; j<=99; j++){
            
        }
    }
}
```

