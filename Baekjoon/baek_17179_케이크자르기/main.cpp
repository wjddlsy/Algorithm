#include <iostream>
#include <vector>
using namespace std;

vector<int> cut;
int N, M, L, len;

bool decision(int k){
    int pos=k, n=0;
    for(int i=0; i<M; ++i) {
        if(cut[i]>=pos && cut[i]+k<=L) {
            pos=cut[i]+k;
            n++;
        }
    }
    return n>=len;
}

int optimize() {
    int lo=1, hi=L;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(decision(mid)) {
            lo=mid+1;
        } else {
            hi=mid;
        }
    }
    return lo-1;
}
int main() {
    cin>>N>>M>>L;
    cut.resize(M);
    for(auto &c:cut){
        cin>>c;
    }
    for(int i=0; i<N; ++i) {
        cin>>len;
        cout<<optimize()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}