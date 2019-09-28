# 트리의 가중치한국어   

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| --------- | ----------- | ---- | ---- | --------- | --------- |
| 2 초      | 128 MB      | 1072 | 308  | 216       | 29.670%   |

## 문제

트리는 N개의 정점과 N-1개의 에지로 구성된 그래프이다. 트리의 성질 중 하나는 어느 두 정점 간에도 유일하게 하나의 경로가 존재한다는 것이다.

트리의 모든 에지에 음이 아닌 정수인 가중치가 배정되었다. ‘경로의 가중치’란 경로에 해당하는 에지들의 곱으로 정의된다. 또한 ‘트리의 가중치’는 트리 상에 가능한 모든 경로에 대해 ‘경로의 가중치’의 합을 의미한다. 문제는 트리가 주어졌을 때 ‘트리의 가중치’를 구하는 것이다.

## 입력

첫째 줄에 트리의 정점의 개수 N(1≤N≤100,000)이 주어진다. 다음 N-1개의 줄에 대해 각 줄에는 세 개의 정수 A, B, W(0≤W≤1,000)가 입력되는데 이는 A점과 B점이 연결되어 있고 이 에지의 가중치는 W라는 것을 의미한다.

## 출력

첫째 줄부터 트리의 가중치를 1,000,000,007로 나눈 나머지를 출력한다.

## 예제 입력 1 복사

```
3
3 2 100
2 1 100
```

## 예제 출력 1 복사

```
10200
```

## 예제 입력 2 복사

```
4
1 2 5
1 3 5
1 4 5
```

## 예제 출력 2 복사

```
90
```

## 예제 입력 3 복사

```
5
1 2 2
2 3 3
4 3 2
5 3 2
```

## 예제 출력 3 복사

```
55
```



## 출처

[Olympiad ](https://www.acmicpc.net/category/2)> [Croatian Highschool Competitions in Informatics ](https://www.acmicpc.net/category/25)> [2008 ](https://www.acmicpc.net/category/30)> [Final Exam #1](https://www.acmicpc.net/category/detail/266) 2번

- 문제를 번역한 사람: [author6](https://www.acmicpc.net/user/author6)

## 알고리즘 분류

[보기](https://www.acmicpc.net/problem/1289#)



## Solve 

> 모르겟다 

### hint 

![image-20181209162541586](/Users/jungin/Library/Application Support/typora-user-images/image-20181209162541586.png)



### CODE 

```c++
#include <iostream>
#include <vector>
using namespace std;

const long long mod=1000000007;
int N;
vector<vector<pair<int,int>>> adj;
long long path[100001]; //root를 끝점으로하는 경로를 저장하기.

// 왼 오 루트 순회 post order
// 왼 * 오 하고 왼 오를 따로 저장해둔다음에 ....... 이게 되나 ,,,
// return 값 root를 끝 점으로 하는 경로의 길이 .....
long long postOrder(int root, int parent){
    if(adj[root].size()==1 && adj[root][0].first==parent){
        return 0;
    }

    vector<long long> temp_sum(adj[root].size(), 0);
    vector<long long> temp(adj[root].size(), 0);

    long long dist=0, dist2=0, child_num=0;
    for(int i=0; i<adj[root].size(); ++i){
        // 쭉 돌고
        if(adj[root][i].first!=parent) {
            long long tmp_dist=(adj[root][i].second * (1+postOrder(adj[root][i].first, root))%mod)%mod;
            dist = (dist + tmp_dist)%mod;
            if(child_num==0)
                temp_sum[child_num]=tmp_dist;
            else
                temp_sum[child_num] = (tmp_dist + temp_sum[child_num-1])%mod; //부분합
            temp[child_num] = tmp_dist; //각각 child-root
            child_num++;
        }
    }
    //root 끼고 도는 경로 합
    for(int i=0; i<child_num-1; ++i){
        dist2=(dist2+temp[i+1]*temp_sum[i])%mod;
    }
    path[root]=(dist2+dist)%mod;
    // root를 끝으로 하는 경로들이 나오는데
    // root를 끼고 도는 경로를 구하고
    //
    return dist%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    adj=vector<vector<pair<int,int>>>(N+1);
    for(int i=0; i<N-1; ++i){
        int A, B, W;
        cin>>A>>B>>W;
        adj[A].push_back({B, W});
        adj[B].push_back({A, W});
    }
    long long dist=0;
    postOrder(1, 0);
    for(int i=1; i<=N; ++i){
        dist=(dist+path[i])%mod;
    }
    cout << dist;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
```



- 1등 코드! 

```c++
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define DIV 1000000007
vector<pair<int, int>> tree[100001];

ll ans = 0;

ll pre_order(int v, int pre_v) {
	ll temp, subset = 1;

	for (auto it : tree[v]) {
		if (pre_v == it.first) continue; // 자신을 호출한 부모에게 가는것을 방지함
		temp = (pre_order(it.first, v) * it.second) % DIV;
		ans = (ans + temp * subset) % DIV;
		subset = (subset + temp) % DIV;
	}

	return subset;
}

int main() {
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int v1, v2, weight;
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2 >> weight;
		tree[v1].push_back(make_pair(v2, weight));
		tree[v2].push_back(make_pair(v1, weight));
	}

	pre_order(1, 0);

	cout << ans << endl;
	return 0;
}
```

