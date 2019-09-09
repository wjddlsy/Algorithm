#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int tree[1001];
int cache[1001][31][2]; // t일때 w이하 썼을 때 최댓값
int T,W;
int solve(int t, int w, int p) {
    if(w==W+1)
        return 0;
    if(t>T)
        return 0;
    int &ret=cache[t][w][p];
    if(ret!=-1)
        return ret;
    ret = 0;
    ret = max(ret, solve(t+1, w, p) + (p == tree[t]) );
    ret = max(ret, solve(t+1, w+1, p==1?2:1) + (p==tree[t]));

    return ret;
}
int main() {
    cin>>T>>W;
    for(int i=1; i<=T; ++i) {
        cin>>tree[i];
    }
    tree[0] = -1;
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, 0, 1);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}