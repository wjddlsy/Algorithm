# 크로아티아 알파벳 

| 시간 제한 | 메모리 제한 | 제출  | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ----- | ---- | --------- | --------- |
| 1 초      | 128 MB      | 11552 | 4846 | 4263      | 43.754%   |

## 문제

예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 다음과 같이 변경해서 입력했다.

| 크로아티아 알파벳 | 변경 |
| ----------------- | ---- |
| č                 | c=   |
| ć                 | c-   |
| dž                | dz=  |
| ñ                 | d-   |
| lj                | lj   |
| nj                | nj   |
| š                 | s=   |
| ž                 | z=   |

예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

## 입력

첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.

문제 설명에 나와있는 크로아티아 알파벳만 주어진다.

## 출력

입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

## 예제 입력 1 복사

```
ljes=njak
```

## 예제 출력 1 복사

```
6
```

## 예제 입력 2 복사

```
ddz=z=
```

## 예제 출력 2 복사

```
3
```

## 예제 입력 3 복사

```
nljj
```

## 예제 출력 3 복사

```
3
```

## 예제 입력 4 복사

```
c=c=
```

## 예제 출력 4 복사

```
2
```



## 출처

[Contest ](https://www.acmicpc.net/category/45)> [Croatian Open Competition in Informatics ](https://www.acmicpc.net/category/17)> [COCI 2008/2009 ](https://www.acmicpc.net/category/22)> [Contest #5](https://www.acmicpc.net/category/detail/96) 1번

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)
- 데이터를 추가한 사람: [cake_monotone](https://www.acmicpc.net/user/cake_monotone) [handong](https://www.acmicpc.net/user/handong) [jh05013](https://www.acmicpc.net/user/jh05013) [veydpz](https://www.acmicpc.net/user/veydpz) [zzangho](https://www.acmicpc.net/user/zzangho)



## Solve

## 생각해보기

- string에서 문자열 찾기 사용



## 찾아본거

## std::string::find

```c++
#include <string>
int main ()
{
  std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle");

  // different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';

  found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
    std::cout << "second 'needle' found at: " << found << '\n';

  found=str.find("haystack");
  if (found!=std::string::npos)
    std::cout << "'haystack' also found at: " << found << '\n';

  found=str.find('.');
  if (found!=std::string::npos)
    std::cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  std::cout << str << '\n';

  return 0;
}
```

## Code

- 그냥 풀었다

  ```c++
  int main(int argc, const char * argv[]) {
      string s;
      int answer=0;
      cin >> s;
      for(int i=0; i<s.size(); ++i){
          if(i==s.size()-1){
              answer++;
              break;
          }
          
          if(s[i]=='c'){
              if(s[i+1]=='=' || s[i+1]=='-'){
                  
                  ++i;
              }
              answer++;
          }
          else if(s[i]=='d'){
              if(i!=s.size()-2 && s[i+1]=='z' && s[i+2]=='='){
                  
                  i+=2;
              }
              
              else if (s[i+1]=='-'){
                  
                  ++i;
              }
              answer++;
          }
          
          else if(s[i]=='l'){
              if(s[i+1]=='j'){
                  ++i;
              }
              answer++;
  
          }
          
          else if(s[i]=='n'){
              if(s[i+1]=='j'){
                  ++i;
              }
              answer++;
  
          }
          else if(s[i]=='s'){
              if(s[i+1]=='='){
                  ++i;
              }
              answer++;
  
          }
          
          else if(s[i]=='z'){
              if(s[i+1]=='='){
                  ++i;
              }
              answer++;
  
          }
          
          else
              answer++;
  
      }
      
      cout << answer;
  }
  ```

- 다른 사람 코드

  ```C++
  #include <stdio.h>
  
  char a[110];
  int ans;
  
  int main() {
  	scanf("%s", &a);
  	int i = 0;
  	while (a[i]) {
  		ans++;
  		if (a[i] == '-' || a[i] == '=') ans--; 
  		if (a[i] == '=' && i > 1 && a[i - 1] == 'z' && a[i - 2] == 'd') ans--;
  		if (a[i] == 'j' && i > 0 && (a[i - 1] == 'l' || a[i - 1] == 'n')) ans--;
  		i++;
  	}
  	printf("%d", ans);
  }
  ```




