#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct DSU {
    vector<int> parent;
    int n;

    DSU (int n) : n(n), parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u==v)
            return;
        parent[v] = u;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> threads(M);
    for(auto &thread:threads) {
        cin >> thread.first >> thread.second;
        thread.first--;
        thread.second--;
    }

    int Q;
    cin>>Q;

    map<int, int> m;
    vector<int> tears(Q);
    vector<int> not_tears;
    for(auto &tear:tears) {
        cin>>tear;
        tear--;
        m[tear] = true;
    }

    reverse(tears.begin(), tears.end());

    for(int i=0; i<M; ++i) {
        if(!m[i])
            not_tears.emplace_back(i);
    }

    DSU dsu(N);

    int cnt = N;
    vector<int> ret;
    for(auto &not_tear:not_tears) {
        pair<int, int> thread = threads[not_tear];
        if(dsu.find(thread.first) != dsu.find(thread.second))
            cnt--;
        dsu.merge(thread.first, thread.second);
    }

    for(auto &tear:tears) {
        pair<int, int> thread = threads[tear];
        if(dsu.find(thread.first) == dsu.find(thread.second))
            ret.emplace_back(cnt);
        else {
            ret.emplace_back(cnt);
            cnt--;
        }
        dsu.merge(thread.first, thread.second);
    }
    reverse(ret.begin(), ret.end());
    for(auto &r:ret) {
        cout << r << " ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}