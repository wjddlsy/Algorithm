#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100001];

int main() {
    int n;
    cin>>n;
    //memset(cache, -987654321, sizeof(cache));
    vector<int> nums(n+1,0);
    for(int i=1; i<=n; ++i){
        cin>>nums[i];
    }

    int ret=-987654321;

    cache[1]=nums[1];

    for(int i=2; i<=n; ++i){
        cache[i]=max(cache[i-1]+nums[i], nums[i]);
        ret=max(ret, cache[i]);
    }

    ret=max(ret, cache[1]);
    cout<<ret;
    return 0;
}