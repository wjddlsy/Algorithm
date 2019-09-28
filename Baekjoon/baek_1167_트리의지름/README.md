# 트리의 지름

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 5137 | 2117 | 1620      | 45.050%   |

## 문제

트리(tree)는 사이클이 없는 무방향 그래프이다. 트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.

![img](https://www.acmicpc.net/JudgeOnline/upload/201007/ttrrtrtr.png)

이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.

입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.

![img](https://www.acmicpc.net/JudgeOnline/upload/201007/tttttt.png)

 

## 입력

파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n번째 줄까지 각 간선에 대한 정보가 들어온다. 간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

## 출력

첫째 줄에 트리의 지름을 출력한다.

## 예제 입력 1 복사

```
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
```

## 예제 출력 1 복사

```
45
```



## 출처

- 문제의 오타를 찾은 사람: [apjw6112](https://www.acmicpc.net/user/apjw6112)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/1967#)



## Solve

### Code

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;

int longest;
bool visited[100001]={false,};
int height(int root){

    vector<int> heights;
    visited[root]=true;
    for(int i=0; i<adj[root].size(); ++i){
        if(!visited[adj[root][i].first])
            heights.push_back(adj[root][i].second+height(adj[root][i].first));
    }
    if(heights.empty()) return 0; //자식이 하나도 없는 경우!
    sort(heights.begin(), heights.end());
    if(heights.size()>=2)
        longest=max(longest, heights[heights.size()-2]+heights[heights.size()-1]);


    return heights.back();
}

int solve(int root){
    longest=0;
    int h=height(root);
    return max(longest, h);
}
int main() {
    int V;
    cin>>V;
    adj=vector<vector<pair<int, int>>>(V+1);
    for(int i=1; i<=V; ++i){
        int root, a, b;
        cin>>root;
        while(true){
            cin>>a;
            if(a==-1)
                break;
            cin>>b;
            adj[root].push_back({a, b});
        }
    }
    cout<<solve(1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
```



