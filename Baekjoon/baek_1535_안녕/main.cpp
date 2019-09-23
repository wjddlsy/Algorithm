#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[21][10], N;
vector<pair<int, int>> stats;
int ans;
int solve(int n, int hp, int joy) {
    if(hp<=0)
        return 0;
    if(n==N) {
        ans= max(ans, joy);
        return joy;
    }
    int &ret=cache[n][hp];
    if(ret!=-1)
        return ret;
    ret = solve(n+1, hp, joy);
    if(hp-stats[n].first>0)
        ret=max(ret, solve(n+1, hp-stats[n].first, joy+stats[n].second));
    return ret;
}
int main() {
    cin>>N;
    stats.resize(N);
    for(auto &stat:stats) {
        cin>>stat.first;
    }
    for(auto &stat:stats) {
        cin>>stat.second;
    }
    memset(cache, -1, sizeof(cache));
    solve(0, 10, 0);
    cout<<ans;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}