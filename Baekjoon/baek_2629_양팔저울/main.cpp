#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[31][30001];
int n;

void solve(int pos, int w, vector<int>& weights) {
    if(pos>n)
        return;
    int &ret=cache[pos][w];
    if(ret!=-1)
        return;
    cache[pos][w]=1;
    solve(pos+1, w+weights[pos], weights);
    solve(pos+1, w, weights);
    solve(pos+1, w-weights[pos], weights);
}
int main() {
    cin>>n;
    vector<int> weights(n);
    for(auto &weight:weights) {
        cin>>weight;
    }

    memset(cache, -1, sizeof(cache));
    solve(0, 15000, weights);

    int m;
    cin>>m;
    for(int i=0; i<m; ++i) {
        int marble;
        cin>>marble;
        if(marble>15000 || cache[n][marble+15000]==-1)
            cout<<"N ";
        else {
            cout<<"Y ";
        }
    }

    
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}