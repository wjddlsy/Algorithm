#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N; cin>>N;
    map<long long, int> cards;
    for(int i=0; i<N; ++i) {
        long long n; cin>>n;
        cards[n]++;
    }
    vector<pair<int, long long>> sorted;
    transform(cards.begin(), cards.end(), back_inserter(sorted), [](pair<long long, int> const &p){
        return make_pair(p.second, p.first);
    });
    sort(sorted.begin(), sorted.end(), [](auto const &p1, auto const &p2) {
        return p1.first!=p2.first?p1.first>p2.first:p1.second<p2.second;
    });
    cout<<sorted[0].second;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}