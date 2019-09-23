#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> p;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin>>a>>b;
        p.emplace_back(a, b);
    }
    sort(p.begin(), p.end());
    int ret = 0;
    for(int i=0; i<n; ++i) {
        int cnt = 1;
        int comp = i;
        for(int j=i+1; j<n; ++j) {
            if(p[comp].first < p[j].first && p[comp].second < p[j].second) {
                cnt ++;
                comp = j;
            }
        }
        ret = max(ret, cnt);
    }

    cout<<n-ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}