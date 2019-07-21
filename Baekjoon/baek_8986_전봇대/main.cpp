#include <iostream>
#include <vector>
using namespace std;


vector<long long> pos;

long long dist(long long x) {
    long long ret=0;
    for(int i=0; i<pos.size(); ++i){
        ret+=abs(x*i-pos[i]);
    }
    return ret;
}

int main() {
    int N;
    cin>>N;
    pos.resize(N);
    for(auto &p:pos){
        cin>>p;
    }
    long long lo=1, hi=1e9;
    while(lo+3<=hi) {
        long long one=(lo*2+hi)/3;
        long long two=(lo+hi*2)/3;
        if( dist(one) < dist(two)) {
            hi=two;
        } else {
            lo=one;
        }
    }
    long long ret=1e18;
    for(long long i=lo; i<=hi; ++i) {
        ret=min(ret, dist(i));
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}