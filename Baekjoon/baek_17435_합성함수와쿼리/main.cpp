#include <iostream>
#include <vector>

using namespace std;


int st[500001][20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, q;
    cin>>m;
    vector<int> f(m+1);
    for(int i=1; i<=m; ++i) {
        cin>>f[i];
    }

    for(int i=1; i<=m; ++i) {
        st[i][0] = f[i];
    }

    for(int j=1; j<20; ++j) {
        for(int i=1; i<=m; ++i) {
            st[i][j] = st[st[i][j-1]][j-1];
        }
    }


    cin>>q;
    for(int i=0; i<q; ++i) {
        int n, x;
        cin>>n>>x;
        for(int j=20; j>=0; --j) {
            if((1<<j) <= n) {
                x = st[x][j];
                n -= (1<<j);
            }
        }
        cout << x << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}