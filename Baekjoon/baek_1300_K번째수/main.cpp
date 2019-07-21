#include <iostream>

using namespace std;

int N, K;

bool decision(int value) {
    long long ret=0;
    for(int i=1; i<=N; ++i) {
        ret+=min(value/i, N);
    }
    return ret>=K;
}

/* 1 2 3 2 4 6 3 6 9
 *
 * */
int optimize() {
    int lo=1, hi=K, ret=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(decision(mid)) {
            ret=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }
    return ret;
}
int main() {
    cin>>N>>K;
    cout<<optimize();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}