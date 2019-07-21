#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int n, m, best;
vector<vector<int>> foods;
vector<pair<int, int>> order;

void search(unsigned long long status, int placed, int here) {
    if(here==m)
        return;
    if(status==(1ull<<n)-1) {
        best=min(best, placed);
        return;
    }
    if(best<=placed)
        return;
    unsigned long long origin=status;
    // here을 만드는 경우
    int food=order[here].second;
    for(auto &name:foods[food]) {
        status |= (1ull<<name);
    }
    search(status, placed+1, here + 1);
    // here을 만들지 않는 경우
    search(origin, placed, here+1);
}

int solve() {
    best=21;
    search(0, 0, 0);
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        map<string, int> names;
        foods=vector<vector<int>>(m);
        order.clear();
        int index=0;
        for(int i=0; i<n; ++i){
            string s; cin>>s;
            names[s]=index++;
        }
        for(int i=0; i<m; ++i){
            int k; cin>>k;
            for(int j=0; j<k; ++j) {
                string s; cin>>s;
                foods[i].emplace_back(names[s]);
            }
            order.emplace_back(foods[i].size(), i);
        }
        sort(order.begin(), order.end(), greater<pair<int,int>>());
        cout<<solve()<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}