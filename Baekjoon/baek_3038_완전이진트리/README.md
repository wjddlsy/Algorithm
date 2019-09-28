# 완전 이진 트리 

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 1 초      | 128 MB      | 215  | 119  | 95        | 60.897%   |

## 문제

완전 이진 트리의 각 노드는 계측적인 구조로 이루어져 있다. 루트 노드의 레벨은 0이며, 레벨 1의 두 자식 노드를 가지고 있다. 또, 레벨 1의 자식 노드의 레벨은 2이다.

보통 레벨이 N인 완전 이진 트리는 2N-1개의 노드를 가지고 있다. 레벨이 N-1이 아닌 모든 노드는 자식 노드를 두 개씩 가지고 있다.

1부터 2N-1까지 숫자를 레벨이 N인 완전 이진 트리의 각 노드에 적을 수 있다. 이때, 레벨이 D인 각각의 노드에 대해서 왼쪽 서브트리에 쓰여 있는 숫자의 합과 오른쪽 서브트리에 쓰여 있는 숫자의 합의 차이는 2D라는 조건을 만족해야 한다.

예를 들어, 루트의 왼쪽 서브 트리의 합과 오른쪽 서브 트리의 합의 차이는 1이어야 하며, 레벨이 1인 경우에는 2이어야 한다. 또, 모든 숫자는 한 번씩 사용해야 한다.

N이 주어졌을 때, 문제의 조건에 맞게 완전 이진 트리의 각 노드에 숫자를 정하는 프로그램을 작성하시오.

## 입력

첫째 줄에 트리의 레벨인 N이 주어진다. (1 ≤ N ≤ 15)

## 출력

첫째 줄에 문제의 조건에 맞게 숫자를 채운 완전 이진 트리를 프리오더로 순회한 결과를 출력한다.

## 예제 입력 1 복사

```
3
```

## 예제 출력 1 복사

```
3 1 7 5 6 2 4
```



## 출처

[Contest ](https://www.acmicpc.net/category/45)> [Croatian Open Competition in Informatics ](https://www.acmicpc.net/category/17)> [COCI 2006/2007 ](https://www.acmicpc.net/category/24)> [Contest #4](https://www.acmicpc.net/category/detail/111) 5번

- 문제를 번역한 사람: [baekjoon](https://www.acmicpc.net/user/baekjoon)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/3038#)

## 메모



## Solve

> There's more than one way to solve this problem, we present one of them. 
>
> Let's try to extend a tree of ==depth n for which the property is satisfied to a tree of depth n+1 for which the property is satisfied.== Have the root node of the new tree contain the number 1 and put two copies of the old tree as its left and right subtrees, only multiplied by 2. Now the subtrees contain only even numbers and each appears twice between the two subtrees. The property is still satisfied in the subtrees; multiplying the elements by two caused the differences to be multiplied by two, but the depths of those nodes increased by one so this is good. 
>
> Add 1 to all leaf nodes in the left subtree and to all non-leaf nodes in the right subtree. Now each 
>
> element appears only once in the entire tree. The property is still satisfied in the subtrees because 
>
> adding a constant to all nodes on the same level in a subtree does not change the differences. The 
>
> n−1
>  property holds for the root node because we added 2n to the left subtree and ∑2i = 2n −1to the right 
>
> subtree so the difference is 1. 

1. 해당 성질을 만족하는 깊이 n의 트리(old)를 가정 
2. 루트 노드의 값을 1로 갖는 깊이 n+1의 트리(new)가 있다고 하자. 
3. New 트리 루트의 왼쪽 자식에 old를 복사하고 오른쪽 자식에도 old를 복사한다. (다 곱하기 2 한다음에)
4. new트리의 왼쪽 서브트리에서 리프 노드라면 값에 +1을 해줌 
5. new트리의 오른쪽 서브트리에서 리프 노드가 아니라면 값에 +1을 해줌 

