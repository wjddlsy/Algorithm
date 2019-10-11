#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int st[100001][20];
int K = 20;

int main() {
    int N, Q;
    cin >> N;
    vector<int> arr(N);
    for (auto &a:arr) {
        cin >> a;
    }

    for(int i=0; i<N; ++i) {
        st[i][0] = arr[i];
    }

    for(int j=1; j<K; ++j) {
        for(int i=0; i+(1<<j)<=N; ++i) {
            st[i][j] = min(st[i][j-1], st[i+(1<<j-1)][j-1]);
        }
    }

    cin>>Q;
    while(Q--) {
        int a, b;
        cin>>a>>b;
        int dist = (int)(log10(b-a+1)/log10(2));
        cout << min(st[a][dist], st[b-(1<<dist)+1][dist]) << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}