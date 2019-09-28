# 4354 문자열 제곱   

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 128 MB      | 1205 | 285  | 224       | 38.957%   |

## 문제

두 문자열 a와 b가 주어졌을 때, a*b는 두 문자열을 이어붙이는 것을 뜻한다. 예를 들어, a="abc", b="def"일 때, a*b="abcdef"이다.

이러한 이어 붙이는 것을 곱셈으로 생각한다면, 음이 아닌 정수의 제곱도 정의할 수 있다.

a^0 = "" (빈 문자열)

a^(n+1) = a*(a^n)

x문자열 s가 주어졌을 때, 어떤 문자열 a에 대해서 s=a^n을 만족하는 가장 큰 n을 찾는 프로그램을 작성하시오.

## 입력

입력은 여러 개의 테스트 케이스로 이루어져 있다. 각각의 테스트 케이스는 s를 포함한 한 줄로 이루어져 있다. s의 길이는 적어도 1이며, 백만글자를 넘지 않는다. 마지막 테스트 케이스의 다음 줄은 마침표를 포함하고 있다.

## 출력

각각의 테스트 케이스에 대해, s=a^n을 만족하는 가장 큰 n을 찾은 뒤 출력한다.

## 예제 입력 1 복사

```
abcd
aaaa
ababab
.
```

## 예제 출력 1 복사

```
1
4
3
```



## 출처

[Contest ](https://www.acmicpc.net/category/45)> [Waterloo's local Programming Contests ](https://www.acmicpc.net/category/98)> [1 June, 2002](https://www.acmicpc.net/category/detail/506) D번

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 데이터를 추가한 사람: [ckdtjssml](https://www.acmicpc.net/user/ckdtjssml)