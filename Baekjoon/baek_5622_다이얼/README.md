# 다이얼한국어   

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 128 MB      | 9568 | 5428 | 4981      | 58.047%   |

## 문제

상근이의 할머니는 아래 그림과 같이 오래된 다이얼 전화기를 사용한다.

![img](https://www.acmicpc.net/upload/images/dial.png)

전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다. 다른 숫자를 누르려면 다이얼이 원래 위치로 돌아가기를 기다려야 한다.

숫자 1을 걸려면 총 2초가 필요하다. 1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.

상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다. 즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다. 예를 들어, UNUCIC는 868242와 같다.

할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 시간을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어는 2글자~15글자로 이루어져 있다.

## 출력

첫째 줄에 다이얼을 걸기 위해서 필요한 시간을 출력한다.

## 예제 입력 1 복사

```
UNUCIC
```

## 예제 출력 1 복사

```
36
```



## 출처

[Contest ](https://www.acmicpc.net/category/45)> [Croatian Open Competition in Informatics ](https://www.acmicpc.net/category/17)> [COCI 2012/2013 ](https://www.acmicpc.net/category/18)> [Contest #6](https://www.acmicpc.net/category/detail/560) 1번

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)



# Solve

## 생각해보기

- UNUCIC 

  U = 8 

  N = 6 

  C = 3 

  I = 4

  8 + 6 + 8 + 2 + 4 + 2 = 28 

  7 + 5 + 7 + 1 + 3 + 1 = 22

  22 + 12 = 36

- 배열에 미리 저장해놓고 풉니당



## Code

```C++
#include <iostream>
using namespace std;

int a[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
int main(int argc, const char * argv[]) {
    char s;
    int sum=0;
    while(cin>>s){
        sum+=a[s-'A'];
    }
    cout << sum;
}

```

