#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000
int A[50001];

// 펜윅트리의 구현
struct FenwickTree{
    vector<int> tree;
    explicit FenwickTree(int n) : tree(n+1) {}
    // A[0..pos] 의 부분합을 구한다.
    int sum(int pos){
        // 인덱스가 1부터 시작한다고 생각
        ++pos;
        int ret=0;
        while(pos>0){
            ret+=tree[pos];
            // 다음 구간을 찾기 위해 최종 비트를 지움
            pos&=(pos-1);
        }
        return ret;
    }
    // A[pos]에 val을 더한다.
    void add(int pos, int val){
        ++pos;
        while(pos<tree.size()){
            tree[pos]+=val;
            pos+=(pos & -pos);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    while(C--){
        int N;
        cin>>N;
        FenwickTree ft(MAX);
        long long ret=0;
        for(int i=0; i<N; ++i){
            cin>>A[i];
            ret+=(ft.sum(MAX-1)-ft.sum(A[i]));
            ft.add(A[i], 1);
        }

        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}