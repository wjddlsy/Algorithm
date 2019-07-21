#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin>>N>>Q;
    vector<int> one(N+1, 0), two(N+1, 0), three(N+1, 0);
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        if(a==1)
            one[i]=1;
        else if(a==2)
            two[i]=1;
        else if(a==3)
            three[i]=1;
        one[i]+=one[i-1];
        two[i]+=two[i-1];
        three[i]+=three[i-1];
    }
    for(int i=0; i<Q; ++i){
        int a, b;
        cin>>a>>b;
        cout<<one[b]-one[a-1]<<" "<<two[b]-two[a-1]<<" "<<three[b]-three[a-1]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}