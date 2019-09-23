#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M, cache[10001];
vector<pair<int, int>> weightValue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(int i=0; i<N; ++i) {
        int v, c, k;
        cin>>v>>c>>k;
        for(int j=1; k>0; j*=2) {
            int ix = min(j, k);
            weightValue.emplace_back(v*ix, c*ix);
            k-=ix;
        }
    }
    memset(cache, 0, sizeof(cache));
    for(int i=0; i<weightValue.size(); ++i) {
        for(int j=M; j>=weightValue[i].first; --j) {
            cache[j]=max(cache[j], cache[j-weightValue[i].first]+weightValue[i].second);
        }
    }
    cout<<cache[M];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}