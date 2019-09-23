#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<int> stores;
    for(int i=0; i<=n; ++i) {
        int dir, dist, ret = 0;
        cin>>dir>>dist;
        switch(dir) {
            case 1:
                ret = c + dist;
                break;
            case 2:
                ret = 2*c + 2*r - dist;
                break;
            case 3:
                ret = c - dist;
                break;
            case 4:
                ret = c + r + dist;
                break;
            default:
                break;
        }
        stores.emplace_back(ret);
    }
    int sum = 0, x = stores.back();
    for(int i=0; i<n; ++i) {
        int dist = min(abs(x-stores[i]), 2*r + 2*c - abs(x-stores[i]));
        sum += dist;
    }
    cout<<sum;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}