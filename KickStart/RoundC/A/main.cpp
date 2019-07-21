#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

/*
 * 1번 풀이
 * */

int n;
map< pair < int, int >, bool > used;
map< pair< int, int >, pair < int, int > > d[4];

pair<int, int> get(pair<int, int> x, int g){
    if(d[g].find(x) == d[g].end()) {
        d[g][x]=x;
        if(g==0) {
            d[g][x].second--;
        } else if(g==1) {
            d[g][x].first--;
        } else if(g==2) {
            d[g][x].second++;
        } else {
            d[g][x].first--;
        }
    }
    if(used.find(d[g][x])==used.end()){
        return d[g][x];
    }
    return d[g][x]=get(d[g][x], g);
}

void solve() {
    used.clear();
    for(auto &p:d)
        p.clear();
    int x, y;
    cin>>n>>x>>y>>x>>y;
    pair<int, int> res={x, y};
    used[res]=true;
    for(int i=1; i<=n; ++i){
        char c; cin>>c;
        int g=0;
        if(c=='S') {
            g=1;
        } else if(c=='E'){
            g=2;
        } else if(c=='N'){
            g=3;
        }
        res = get(res, g);
        used[res]=true;
    }
}

/*
 * 2번 풀이
 */

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        cout<<"Case #"<<t<<": ";
        solve();
    }
}