#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> lines(n);
    for(auto &line:lines) {
        cin>>line.first>>line.second;
    }
    sort(lines.begin(), lines.end());

    vector<pair<int,int>> lis = {{-INF, -1}};
    vector<int> parent(n, 0);

    for(int i=0; i<n; ++i) {
        if(lis.back().first < lines[i].second) {
            parent[i] = lis.back().second;
            lis.emplace_back(lines[i].second, i);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), pair<int,int>(lines[i].second, i));
            *it = {lines[i].second, i};
            parent[i] = (it-1)->second;
        }
    }

    vector<bool> ret(n+1, false);
    cout << n - lis.size() + 1 << '\n';
    int cur = lis.back().second;
    while(cur!=-1) {
        ret[cur] = true;
        cur = parent[cur];
    }

    for(int i=0; i<n; ++i) {
        if(!ret[i])
            cout << lines[i].first << '\n';
    }
    //std::cout<<"Hello, World!"<<std::endl;
    return 0;
}
