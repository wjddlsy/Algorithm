#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    cin>>n>>c;

    map<int, pair<int, int>> m;
    int order=0;
    for(int i=0; i<n; ++i) {
        int v; cin>>v;
        if(m.find(v)==m.end()) {
            m[v]={1, order++};
        } else {
            m[v].first++;
        }
    }
    vector<tuple<int, int, int>> p;
    for(auto &mm:m) {
        p.emplace_back(mm.second.first, mm.second.second, mm.first);
    }
    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        if(get<0>(a)==get<0>(b))
            return get<1>(a)<get<1>(b);
        return get<0>(a)>get<0>(b);
    });
    for(auto &pp:p) {
        int freq, index, value;
        tie(freq, index, value)=pp;
        for(int i=0; i<freq; ++i ){
            cout<<value<<" ";
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}