#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int r, c, n, e, lo;
vector<pair<int, int>> error;

// k일때 최소개수
bool decision(int k){
    int pos=0, cnt=0;
    for(int i=0; i<e; ++i){
        if(pos>error[i].first)
            continue;
        pos=error[i].first+k;
        cnt++;
    }
    return cnt<=n;
}

int optimize() {
    int hi=min(r, c);
    lo--;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(decision(mid)) {
            hi=mid;
        } else {
            lo=mid;
        }

    }
    return hi;
}
int main() {
    cin>>r>>c>>n>>e;
    error.resize(e);
    for(auto &er:error){
        cin>>er.second>>er.first;
        lo=max(lo, er.second);
    }
    sort(error.begin(), error.end());
    cout<<optimize();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}