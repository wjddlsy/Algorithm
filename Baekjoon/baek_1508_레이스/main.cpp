#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

bool decision(int h, vector<int>& pos) {
    int limit=-1, cnt=0;
    for(auto &p:pos) {
        if(limit<=p) {
            limit = p + h;
            cnt++;
        }
    }
    return cnt>=m;
}
int main() {
    cin >> n >> m >> k;
    vector<int> pos(k);
    for(auto &p:pos) {
        cin>>p;
    }
    int lo=-1, hi=1000000;
    while(lo+1<hi) {
        int mid=(lo+hi)/2;
        if(decision(mid, pos))
            lo=mid;
        else
            hi=mid;
    }
    int limit=-1, cnt=0;
    string ret;
    for(auto &p:pos) {
        if(cnt<m && limit<=p) {
            limit=p+lo;
            cnt++;
            ret+="1";
        } else {
            ret+="0";
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}