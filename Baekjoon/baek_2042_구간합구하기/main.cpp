#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree{
    vector<long long> tree;
    FenwickTree(int n) : tree(n+1) {}
    // A[0..pos] 의 부분합을 구한다.
    long long sum(int pos){
        // 인덱스가 1부터 시작한다고 생각
        ++pos;
        long long ret=0;
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
    int N, M, K, in;
    cin>>N>>M>>K;
    FenwickTree ft(4*N);

    for(int i=0; i<N; ++i){
        cin>>in;
        ft.add(i, in);
    }

    long long a, b, c;
    for(int i=0; i<M+K; ++i){
        cin>>a>>b>>c;
        b--; c--;
        if(a==1){
            c++;
            long long val=ft.sum(b)-ft.sum(b-1);
            ft.add(b, c-val);
        } else
            cout<<ft.sum(c)-ft.sum(b-1)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}