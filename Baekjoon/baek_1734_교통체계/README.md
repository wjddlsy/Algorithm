# 1734 교통체계 

## 문제

N개의 도시와, 서로 다른 두 도시를 잇는 E개의 도로로 이루어진 나라가 있다. 각 도시는 1번부터 N번까지 번호가 매겨져 있으며, 도로는 ==양방 통행 도로==이다. 즉 i번 도시와 j번 도시 사이에 도로가 존재한다면 i번 도시에서 j번 도시로 이동할 수 있을 뿐더러 j번 도시에서 i번 도시로도 이동할 수 있다.

이 나라의 교통 체계는 매우 복잡해서, 이를 간소화하는 작업을 벌이려고 한다. 간소화를 위한 방법으로는 크게 두 가지가 있다. 두 도시를 연결하는 특정한 도로를 골라서 없애는 단순한 방법이 있고, 특정한 도시를 골라서 이 도시로 들어오거나 나가는 모든 도로를 없애는 방법이 있다.

이러한 교통 체계의 단순화는 면밀한 검토가 필요한 복잡한 작업이 된다. 따라서 몇 개의 질문을 만들어 놓고, 이 질문들에 대한 답을 구해낸 후 이를 토대로 단순화 작업을 벌이기로 하였다. 질문의 유형은 아래의 두 가지 중 하나를 따른다.

1. 두 개의 도시 A, B가 있고, 도시 G1과 도시 G2를 잇는 도로가 있다. 도시 G1과 도시 G2 사이의 도로를 없앤 후에도 도시 A에서 도시 B로 이동할 수 있는가?
2. 세 개의 도시 A, B, C가 있다. 도시 C로 들어오거나 나가는 모든 도로를 없앤 후에도 도시 A에서 도시 B로 이동할 수 있는가?

이 나라의 현재 교통 체계에 대한 정보와 위의 유형에 해당되는 여러 개의 질문들이 주어졌을 때, 교통 체계의 단순화를 위해 주어진 질문들에 대한 답을 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 도시의 개수 N과 도로의 개수 E가 주어진다. (2 ≤ N ≤ 100,000, 1 ≤ E ≤ 500,000) 이어서 E개의 줄에 걸쳐 각 줄에 N 이하의 서로 다른 두 자연수가 주어지는데, 이는 두 자연수를 번호로 하는 두 개의 도시 사이에 도로가 존재함을 의미한다. 같은 도로가 여러 번 입력으로 주어지지 않으며, 임의의 두 도시 사이에 항상 이동할 수 있는 경로가 하나 이상 존재하는 교통 체계만이 입력으로 주어진다.

다음 줄에는 질문의 개수 Q가 주어진다. (1 ≤ Q ≤ 300,000) 이어서 Q개의 줄에 걸쳐 질문에 대한 정보가 주어지는데, 각 줄의 첫 번째 자연수는 질문의 유형을 나타내는 1 또는 2이다. 질문이 유형 1에 해당하는 경우는 N 이하의 네 개의 자연수 A, B, G1, G2가 순서대로 주어진다. A와 B는 서로 다르며, G1과 G2 사이에 항상 도로가 존재하는 경우만이 입력으로 주어진다. 질문이 유형 2에 해당하는 경우는 N 이하의 서로 다른 자연수 A, B, C가 순서대로 주어진다.

## 출력

Q개의 줄에 걸쳐 각 질문에 대한 답을 한 줄에 하나씩 yes나 no로 출력한다. 질문의 답이 "이동할 수 있다"이면 yes를, "이동할 수 없다"이면 no를 출력하면 된다.



## 예제 입력 1 복사

```
13 15
1 2
2 3
3 5
2 4
4 6
2 6
1 4
1 7
7 8
7 9
7 10
8 11
8 12
9 12
12 13
5
1 5 13 1 2
1 6 2 1 4
1 13 6 7 8
2 13 6 7
2 13 6 8
```

## 예제 출력 1 복사

```
yes
yes
yes
no
yes
```



# 풀이 

## 단절점과 단절선

### 단절점 

> 1개의 컴포넌트를 가지는 무향그래프에서 한 정점과 그에 연결된 간선들을 제거했을 때 그래프가 2개 이상의 컴포넌트로 구분되는 정점 

- 어떻게 알 수 있을까? 

  : DFS 스패닝 트리를 구한 후 해당 정점의 서브트리가 해당 정점의 조상으로 가는 역방향 간선을 가지고 있지 않음을 보인다. 

- 구현하기 위해서 필요한 것들 

  1. `vector<int> discovered`

     : 정점의 방문 순서를 저장해놓는 베거 

  2. `int findCutVertex(int here, bool isRoot)`

     : 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중 가장 일찍 발전된 정점의 발견 시점을 반환 

     : 이를 통해 내 서브트리의 정점이 갈 수 있는 가장 빨리 발견된 정점 발견 시점을 알 수 있다. 

#### 구현 

```c++
vector<vector<int>> adj; 
vector<int> discovered;
vector<bool> isCutVertex;
int index=0;

// here를 루트로하는 서브트리에 있는 절단점들을 찾는다.
// return: 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중 가장 일찍 발견된 정점의 발견 시점. 
int findCutVertex(int here, bool isRoot){
  discovered[here]=index++;
  int ret=discovered[here];
  int children=0; 
  for(auto &there:adj[here]){
    if(discovered[there]==-1){
      ++children;
      int subtree=findCutVertex(there, false);
      // Root가 아니고 내 밑에 애들이 내 부모(조상)으로 갈 수 없을 때
      if(!isRoot && subtree>=discovered[here]){
        isCutVertex[here]=true;
      }
      ret=min(ret, subtree);
    }
    else {
      ret=min(ret, discovered[there]);
    }
  }
  if(isRoot) isCutVertex[here]=(children>=2);
  return ret;
}


```



### 단절선 

> 1개의 컴포넌트를 가지는 무향그래프에서 어떤 간선을 제거했을 때 해당 그래프가 2개 이상의 컴포넌트로 구분되는 간선 

- 어떻게 알 수 있을까? 

  : (u, v)에서 v의 subtree가 u의 조상으로 갈 수 없다는 것을 보인다 

#### 구현 

````c++
vector<vector<int>> adj;
vector<int> discovered; 
vector<pair<int, int>> cutEdges;
int index=0;

int findCutEdge(int here, int parent){
  discovered[here]=index++;
  int ret=discovered[here];
  for(auto &there:adj[here]){
    if(there==parent)
      continue;
    if(discovered[there]==-1){
      int subtree=findCutEdge(there, here);
      if(subtree>discovered[here]){
        cutEdges.emplace_back({here, there});
      }
      ret=min(ret, subtree);
    }
    else 
      ret=min(ret, discovered[there]);
  }
  return ret;
}
````



## How to Solve

### Functions 

1. `dfs(int here, int parent, int dep)` 

   : DFS 스패닝 트리를 만들면서 `finished`, `discovered`, `depth` , `subtree`, `children` 를 기록합니다. 

2. `int is_descendant(int a, int b)`

   : a가 b의 자손인지 판별

3. `int find_related_child(int me, int descendant)`

   : me랑 descendant의 공통을 골라봅니다. 

### Variables

1. `vector<int> finished`

   : 해당 정점에 대한 dfs가 종료되는 시점 

2. `vector<int> discovered`

   : 해당 정점의 발견 시점 

3. `vector<int> depth`

   : 해당 정점의 트리 깊이 

4. `vector<int> subtree` 

   : 내 후손들이 역방향 간선을 통해 갈 수 있는 조상 중 가장 빠르게 발견된 조상의 발견 시점 

5. `vector<vector<int>> children `

   : 해당 정점의 자식들을 저장해놓습니다. 

### Query

1. 두 개의 도시 A, B가 있고, 도시 G1과 도시 G2를 잇는 도로가 있다. 도시 G1과 도시 G2 사이의 도로를 없앤 후에도 도시 A에서 도시 B로 이동할 수 있는가?

   ```
   if(E(G1, G2)==단절선)
     yes!
   else {
   	같은 부분에 있는지 판단
   }
   ```

   

2. 세 개의 도시 A, B, C가 있다. 도시 C로 들어오거나 나가는 모든 도로를 없앤 후에도 도시 A에서 도시 B로 이동할 수 있는가?

   ```c++
   if(A와 B가 둘 다 C의 자손이 아니라면) yes ;
   else if(A와 B 둘 다 C의 자손이라면 ){
     
   }
   else {
     // 이 경우는 둘 중 하나만 자손입니다. 
   }
   ```

   

