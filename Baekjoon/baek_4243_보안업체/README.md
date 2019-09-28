# 보안 업체한국어   

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 1129 | 343  | 214       | 29.517%   |

## 문제

명우는 보안 업체의 직원이고, 강남역에 있는 상점 여러 개를 도보로 순찰하는 업무를 맡고 있다. 

강남역은 선분으로 나타낼 수 있고, 명우의 회사와 상점은 왼쪽부터 순서대로 선분 위의 점 pi로 나타낼 수 있다. 회사는 pa에 있고, s로 나타낸다. 명우는 s에서 순찰을 시작해서, 모든 상점 pi를 적어도 한 번 방문해야 한다. 각각의 i에 대해서, pi와 pi+1사이를 오가는데 걸리는 시간은 t[pi,pi+1]이다. pi의 대기 시간 ℓi는 s를 출발해서 pi에 처음 도착하기 까지 걸린 시간이다. 시작점 s = pa의 대기 시간 ℓa는 0이다. 명우는 모든 상점의 대기 시간의 합이 최소가 되게 하기 위해 순찰을 해야 한다.

아래 그림에는 총 6개의 상점 p1부터 p6까지가 있고, 시작점 s는 p3이다. 또, t[p1,p2] = 7, t[p2,p3] = 4, t[p3,p4] = 1, t[p4,p5] = 2, t[p5,p6] = 9이다. 명우가 s에서 오른쪽으로 걷기 시작한다면, 대기 시간 ℓ4와 ℓ5는 1과 3이 된다. 아래 그림에 나와있는 순서대로 순찰을 한다면, 대기 시간의 합은 71이 된다. 71보다 대기 시간의 합을 줄이는 방법은 없다.

![img](https://www.acmicpc.net/upload/images/security.png)

점의 수 N과, pi와 pi+1 사이를 오가는데 걸리는 시간 t[pi,pi+1] (t = 1,...,N-1)이 주어졌을 때, 대기 시간을 최소로 하는 프로그램을 작성하시오.

## 입력

첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 상점의 수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에는 시작점의 위치 a (1 ≤ a ≤ N)가 주어진다. a번째 점, pa = s가 시작점이 된다. 다음 N-1개 줄의 i번째 줄에는 t[pi,pi+1]가 주어진다. (1 ≤ t[pi,pi+1] ≤ 15,000,000)

## 출력

각 테스트 케이스 마다, 모든 가게를 순찰하는 모든 순찰 방법 중 대기 시간의 최솟값을 출력한다.

## 예제 입력 1 복사

```
2
6
3
7
4
1
2
9
9
5
96
24
6
2
1
3
12
48
```

## 예제 출력 1 복사

```
71
605
```



## 출처

[ACM-ICPC ](https://www.acmicpc.net/category/1)> [Regionals ](https://www.acmicpc.net/category/7)> [Asia ](https://www.acmicpc.net/category/42)> [Korea ](https://www.acmicpc.net/category/211)> [Nationwide Internet Competition ](https://www.acmicpc.net/category/256)> [Daejeon Nationalwide Internet Competition 2013](https://www.acmicpc.net/category/detail/1124) K번

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 데이터를 만든 사람: [myungwoo](https://www.acmicpc.net/user/myungwoo)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/4243#)

## 메모



## Solve

### Hint

![image-20181129010526429](image-20181129010526429-3421126.png)

> 봐도 모르겠구요~

- 다른 사람 코드를 참고하였다. 
- 처음 생각과 맞았던 부분은 ==왼쪽을 갈지 오른쪽을 갈지== 밖에 없었다. 
- 3차원 디피당 
  - Flag: L에 있을지 R에 있을지를 결정하는 것. 



### Code

- 거리를 좌표로 바꾸는 것!! 계산도 쉽고 좋다. 
- 내 구간을 left~right로 잡았을 때, 내가 left에 있는지 right에 있는지 결정하는 것 
  - 이에 따라 더해야하는 값이 달라짐

```c++
#include <iostream>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;
#define INF 1e18

ll cache[2][101][101];
ll pos[101]; //거리를 좌표로 바꿈
int N, a;
ll go(int flag, int left, int right){
    if(left==1 && right==N)
        return 0;
    ll &ret=cache[flag][left][right];
    if(ret!=-1)
        return ret;
    ret=INF;
    ll mul=N-right+left-1, cost;
    if(left-1>=1){
        if(!flag) cost=mul*(pos[left]-pos[left-1]); //왼쪽으로 가기
        else cost=mul*(pos[right]-pos[left-1]); // 오른쪽에서 왼쪽으로 가기
        ret=min(ret, go(0, left-1, right)+cost);
    }
    if(right+1<=N){
        if(!flag) cost=mul*(pos[right+1]-pos[left]);
        else cost=mul*(pos[right+1]-pos[right]);
        ret=min(ret,go(1, left, right+1)+cost);
    }
    return ret;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(cache, -1, sizeof(cache));
        cin>>N>>a;
        for(int i=2; i<=N; ++i){
            cin>>pos[i];
            pos[i]+=pos[i-1];
        }
        cout << go(0,a,a)<<endl;
    }
    return 0;
}
```

