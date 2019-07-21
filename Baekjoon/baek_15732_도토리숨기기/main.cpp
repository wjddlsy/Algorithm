#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


/*
 * 마지막 도토리의 위치를 찾아라
 * */
vector<tuple<int, int, int>> rules;
int N, K, D;

// dist 번째 상자에서 !!!!! D개 이상의 도토리 넣을 수 잇니
bool decision(int dist) {
    long long ret=0;
    for(int i=0; i<K; ++i) {
        int a, b, c;
        tie(a, b, c)=rules[i];
        if(a<=dist)
            ret+=(min(b, dist)-a)/c+1;
    }
    return ret>=D;
}

int optimize() {
    int lo=0, hi=N;
    while(lo<hi) {
        int mid=(lo+hi)/2;
        if(decision(mid)) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    return lo;
}
int main() {
    cin>>N>>K>>D;
    for(int i=0; i<K; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        rules.emplace_back(a,b,c);
    }
    cout<<optimize();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}