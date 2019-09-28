# 트리의 높이와 너비 

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 3929 | 1101 | 788       | 27.266%   |

## 문제

이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다. 이때 다음의 규칙에 따라 그리려고 한다.

1. 이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
2. 한 열에는 한 노드만 존재한다.
3. 임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
4. 노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.

이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의한다. 트리의 레벨은 가장 위쪽에 있는 루트 노드가 1이고 아래로 1씩 증가한다.

아래 그림은 어떤 이진트리를 위의 규칙에 따라 그려 본 것이다. 첫 번째 레벨의 너비는 1, 두 번째 레벨의 너비는 13, 3번째, 4번째 레벨의 너비는 각각 18이고, 5번째 레벨의 너비는 13이며, 그리고 6번째 레벨의 너비는 12이다.

![img](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/upload/201008/ttt.PNG)

우리는 주어진 이진트리를 위의 규칙에 따라 그릴 때에 너비가 가장 넓은 레벨과 그 레벨의 너비를 계산하려고 한다. 위의 그림의 예에서 너비가 가장 넓은 레벨은 3번째와 4번째로 그 너비는 18이다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때는 번호가 작은 레벨을 답으로 한다. 그러므로 이 예에 대한 답은 레벨은 3이고, 너비는 18이다.

임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오

## 입력

첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다. 다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 번호가 순서대로 주어진다. 노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.

## 출력

첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.

## 예제 입력 1 복사

```
19
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1
```

## 예제 출력 1 복사

```
3 18
```



## 출처

[Olympiad ](https://www.acmicpc.net/category/2)> [한국정보올림피아드 ](https://www.acmicpc.net/category/55)> [KOI 2003 ](https://www.acmicpc.net/category/75)> [고등부](https://www.acmicpc.net/category/detail/384) 1번

- 잘못된 데이터를 찾은 사람: [bessapple14](https://www.acmicpc.net/user/bessapple14)
- 문제의 오타를 찾은 사람: [insu_nym](https://www.acmicpc.net/user/insu_nym)

## 알고리즘 분류

- [트리](https://www.acmicpc.net/problem/tag/%ED%8A%B8%EB%A6%AC)
- [DFS](https://www.acmicpc.net/problem/tag/DFS)



## Solve

> 중위탐색으로 x좌표를 구할 수 있다고 한다.. 나는 바보여따

### Code

```c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tree[10001][2];
int pos[10001][2];
int parent[10001];

int N, root;
vector<vector<int>> lev(10000);

//bfs - LEVEL 찾기!
//왼쪽 개수랑 오른쪽 개수를 알아야 될 것 만 같은대
pair<int, int> longest={1,1};

// level
int height(int root){
    if(root==-1)
        return -1;
    int left=height(tree[root][0])+1;
    int right=height(tree[root][1])+1;
    pos[root][0]=left;
    pos[root][1]=right;
    return left+right;
}

void dfs(int root, int p, int level){
    if(root==-1)
        return;
    int left=tree[root][0];
    int right=tree[root][1];
    if(left!=-1) {
        int left_pos = p - pos[left][1] - 1;
        lev[level + 1].push_back(left_pos);
        dfs(left, left_pos, level+1);
    }
    if(right!=-1) {
        int right_pos = p + pos[right][0] + 1;
        lev[level + 1].push_back(right_pos);
        dfs(right, right_pos, level+1);
    }

}

void find_max(){
    for(int i=1; i<10001; ++i){
        if(lev[i].size()==0)
            break;
        //sort(lev[i].begin(), lev[i].end());
        int dist=0;
        if(lev[i].size()>=2)
            dist=lev[i][lev[i].size()-1]-lev[i][0]+1;
        if(dist>longest.second){
            longest.first=i+1;
            longest.second=dist;
        }
    }
}

int find_root(){
    for(int i=1; i<=N; ++i){
        if(parent[i]==0)
            return i;
    }
}
int main() {
    cin>>N;
    for(int i=0; i<N; ++i ){
        int root, left, right;
        cin>>root>>left>>right;
        tree[root][0]=left;
        tree[root][1]=right;
        if(left!=-1)
            parent[left]=1;
        if(right!=-1)
            parent[right]=1;
    }
    root=find_root();
    height(root);
    dfs(root, pos[root][0]+1, 0);
    find_max();
    cout << longest.first<<" " << longest.second;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

