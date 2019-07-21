#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, ATK;
vector<tuple<int, int, int>> rooms;

bool decision(long long HP) {
    long long atk=ATK;
    long long hp=HP;
    for(int i=0; i<N; ++i){
        long long t, a, h;
        tie(t, a, h)=rooms[i];
        if(t==1) {
            long long opp1=h/atk+(h%atk!=0);
            long long opp2=hp/a+(hp%a!=0);
            if(opp1>opp2)
                return false;
            hp-=a*(opp1-1);
        } else {
            hp=min(hp+h, HP);
            atk+=a;
        }
    }
    return true;
}

long long optimize() {
    long long lo=0, hi=(1ll<<62)-1;
    while(lo<hi) {
        long long mid=(lo+hi)/2;
        if(decision(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}
int main() {
    cin>>N>>ATK;
    rooms.resize(N);
    for(auto& room:rooms) {
        int t, a, h;
        cin>>t>>a>>h;
        room={t, a, h};
    }
    cout<<optimize();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}