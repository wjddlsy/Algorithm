#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
long long cache[501][501];
vector<pair<int, int>> arr;

long long solve(int l, int r) {
    if(l==r)
        return 0;
    long long &ret = cache[l][r];
    if(ret!=-1)
        return ret;
    ret = 987654321;
    for(int i=l; i<r; ++i) {
        ret = min(ret, solve(l, i) + solve(i+1, r) + arr[l].first * arr[i].second * arr[r].second);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    arr.resize(N);
    for(auto &p:arr) {
        cin>>p.first>>p.second;
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, N-1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}