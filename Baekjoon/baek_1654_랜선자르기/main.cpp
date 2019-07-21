#include <iostream>
#include <vector>

using namespace std;

int K, N;
bool decision(vector<long long>& lans, long long length) {
    int n=0;
    for(auto &lan:lans) {
        n+=lan/length;
    }
    return n>=N;
}

long long optimize(vector<long long>& lans) {
    long long lo=0, hi=(1ll<<31);
    while(lo<hi) {
        long long mid=(lo+hi)/2;
        if(decision(lans, mid))
            lo=mid+1;
        else
            hi=mid;
    }
    return lo-1;
}
int main() {
    cin>>K>>N;
    vector<long long> lans(K);
    for(auto &lan:lans){
        cin>>lan;
    }
    cout<<optimize(lans);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}