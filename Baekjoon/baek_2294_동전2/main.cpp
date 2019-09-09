#include <iostream>
#include <vector>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * n 가지 종류의 동전을 이용하여 가치의 합이 k 가 되도록
 */
const int INF = 10001;
int main() {
    int n, k;
    cin>>n>>k;
    vector<int> coins(n);
    vector<int> cache(k+1, INF);
    for(auto &coin:coins) {
        cin>>coin;
        cache[coin]=1;
    }
    sort(coins.begin(), coins.end());
    for(int i=1; i<=k; ++i) {
        for (int j=0; j<n; ++j) {
            if(i - coins[j]>=0)
                cache[i] = min(cache[i], cache[i-coins[j]] + cache[coins[j]]);
            else
                break;
        }
    }
    cout<<(cache[k]==INF ? -1 : cache[k]);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}