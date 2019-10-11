#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int st[50001][20];

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> h(N);
    for (auto &hh:h) {
        cin >> hh;
    }

    for (int i = 0; i < N; ++i) {
        st[i][0] = h[i];
    }

    for (int j=1; j<20; ++j) {
        for(int i=0; i+(1<<j)<=N; ++i) {
            st[i][j] = max(st[i][j-1], st[i+(1<<j-1)][j-1]);
        }
    }

    int ret = 0;
    while(M--) {
        int A, B;
        cin>>A>>B;
        A--; B--;

        int comp = h[A];
        if(B-A < 2) {
            ret++;
            continue;
        }
        A++; B--;
        int dist = (int)(log10(B-A+1)/log10(2));
        int maximum = max(st[A][dist], st[B-(1<<dist)+1][dist]);
        if(maximum <= comp)
            ret++;
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}