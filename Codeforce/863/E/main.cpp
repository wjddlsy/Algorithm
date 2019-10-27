#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

const int maxn = 2e5 + 3, lg = 20;
int st[3*maxn][lg];

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tvs(n);
    vector<int> compress;
    vector<int> psum(3*n+1, 0);
    map<int, int> m;
    for (auto &tv:tvs) {
        cin >> tv.first >> tv.second;
        compress.emplace_back(tv.first);
        compress.emplace_back(tv.second);
        compress.emplace_back(tv.first - 1);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

    for(int i=0; i<compress.size(); ++i) {
        m[compress[i]] = i;
    }
    for(auto &tv:tvs) {
        tv.first = m[tv.first];
        tv.second = m[tv.second];
        psum[tv.first]++;
        psum[tv.second+1]--;
    }

    st[0][0] = psum[0];
    for(int i=1; i<3*n; ++i) {
        psum[i] += psum[i-1];
        st[i][0] = psum[i];
    }
    for(int j=1; j<lg; ++j) {
        for(int i=0; i+(1<<j)<=3*maxn; ++i) {
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    int index = 1;
    for(auto &tv:tvs) {
        int dist = log2(tv.second - tv.first + 1);
        int minimum = min(st[tv.first][dist], st[tv.second - (1<<dist) +1][dist]);
        if(minimum > 1) {
            cout << index;
            return 0;
        }
        index++;
    }
    cout << -1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}