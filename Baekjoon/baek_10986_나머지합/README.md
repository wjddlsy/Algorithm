# 나머지 합

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 256 MB      | 2149 | 702  | 499       | 31.483%   |

## 문제

수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.

즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

## 입력

첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)

둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)

## 출력

첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.

## 예제 입력 1 복사

```
5 3
1 2 3 1 2
```

## 예제 출력 1 복사

```
7
```

## 출처

- 문제를 만든 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/10986#)



## Solve

### Prefix Sum

```c++
int sum[N];
int arr[N];

int main(){
    //init
    for(int i=0; i<N; ++i){
        if(i==0)
            sum[i]=arr[i];
        else 
            sum[i]=sum[i-1]+arr[i];
    }
    //prefix Sum [a..b]
    sum[b]-sum[a-1];
}
```



### 나머지 성질 

$(a+b)\% MOD = (a\% MOD + b\% MOD)\%MOD$

$S_i=A_1+...+A_i$

$A_i+...+A_j=S_j-S_{i-1}$

$(A_i+...+A_j)\%M=(S_j-S_{i-1})\%M$

$\therefore (S_j-S_{i-1})\%M=0 \rightarrow S_j\%M =S_{i-1}\%M$

따라서, 이 문제는 위를 만족하는 (i, j) 쌍 개수를 구하는 문제 



### Code

```C++
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>>N>>M;
    long long remain[1000]={0,};
    long long sum=0, ret=0, in;

    for(int i=0; i<N; ++i){
        cin>>in;
        sum+=in;
        remain[sum%M]++;
    }

    for(int i=0; i<M; ++i){
        ret+= ((remain[i]*(remain[i]-1))/2);
    }
    ret+=remain[0];

    cout<<ret<<'\n';
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

