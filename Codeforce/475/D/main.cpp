#include <iostream>
#include <vector>
#include <map>

using namespace std;

int st[100001][20];

int gcd(int a, int b) {
    return b? gcd(b, a%b):a;
}

int main() {
    int n, q;
    cin>>n;
    vector<int> arr(n);
    map<int, long long> prev, cur, ret;
    for(auto &a:arr) {
        cin>>a;
    }

    for(int i=0; i<n; ++i) {
        st[i][0] = arr[i];
    }

    for(int j=1; j<20; ++j) {
        for(int i=0; i+(1<<j)<=n; ++i) {
            st[i][j] = gcd(st[i][j-1], st[i+(1<<j-1)][j-1]);
        }
    }

    for(int i=0; i<n; ++i) {
        cur.clear();
        cur[arr[i]]++;
        for(auto &p:prev) {
            int g = gcd(p.first, arr[i]);
            cur[g] += p.second;
        }
        for(auto &c:cur) {
            ret[c.first] += c.second;
        }
        swap(cur, prev);
    }


    cin>>q;
    while(q--) {
        int x;
        cin>>x;
        cout << ret[x] << '\n';
        //cout<<m[x]<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}