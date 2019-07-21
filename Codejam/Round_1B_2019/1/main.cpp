#include <iostream>
#include <vector>

using namespace std;

int P, Q;

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
    int T;
    cin >> T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        cin>>P>>Q;
        FenwickTree ftWE(Q+1);
        FenwickTree ftSN(Q+1);
        for(int i=0; i<P; ++i){
            int x, y;
            char d;
            cin>>x>>y>>d;
            if(d=='W'){
                ftWE.add(0, 1);
                ftWE.add(x, -1);
            }
            else if(d=='E'){
                ftWE.add(x+1, 1);
            }
            else if(d=='S'){
                ftSN.add(0, 1);
                ftSN.add(y, -1);
            }
            else if(d=='N'){
                ftSN.add(y+1, 1);
            }
        }
        int y=0, x=0;
        int ymax=ftSN.sum(0), xmax=ftWE.sum(0);
        for(int i=0; i<=Q; ++i){
            int ycount=ftSN.sum(i);
            int xcount=ftWE.sum(i);
            if(ycount>ymax){
                ymax=ycount;
                y=i;
            }
            if(xcount>xmax){
                xmax=xcount;
                x=i;
            }
        }
        cout<<x<<" "<<y<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}