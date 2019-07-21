#include <iostream>
#include <cmath>
using namespace std;

#define max_n 30000000
int tree[max_n];
int tree_sum[max_n]; //내 밑에 경로의 최댓값 저장하기
int ret=0, k;
// find max route
// bfs
void find_max(int depth){
    if(depth<0)
        return;
    int n=(1<<depth);
    for(int i=n; i<n*2; ++i){
        tree_sum[i]=max(tree_sum[i*2], tree_sum[i*2+1])+tree[i];
    }
    find_max(depth-1);
}

void solve(int max_v, int depth, int index){
    if(depth==k) {
        ret+=(max_v-tree[index]);
        return;
    }
    int plus=max_v-tree_sum[index]; //더해야될 값
    ret+=plus;
    solve(max_v-tree[index]-plus, depth+1, index*2);
    solve(max_v-tree[index]-plus, depth+1, index*2+1);

}
int main() {
    int n;
    cin>>k;
    n=(1<<k+1)-1;
    for(int i=2; i<=n; ++i){
        cin>>tree[i];
        ret+=tree[i];
    }
    find_max(k);
    solve(tree_sum[1], 0, 1);
    cout<<ret;
    return 0;
}