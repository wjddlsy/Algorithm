#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(auto &price:prices) {
        cin>>price;
    }
    sort(prices.begin(), prices.end());

    vector<long long> presum(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            presum[i] = prices[i];
        else
            presum[i] = presum[i - 1] + prices[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        int start = (int)(--upper_bound(prices.begin(), prices.end(), a - 1) - prices.begin());
        int end = (int)(--upper_bound(prices.begin(), prices.end(), b) - prices.begin());
        cout << presum[end] - (start == -1 ? 0 : presum[start]) << endl;
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}