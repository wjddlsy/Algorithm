#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    int n;
    vector<int> parent;

    DSU(int n) : n(n), parent(n) {
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
        if (u == v)
            return;
        parent[v] = u;
    }

};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> roads(n-1);
    for (auto &road:roads) {
        cin >> road.first >> road.second;
        road.first--;
        road.second--;
    }

    vector<pair<int, int>> ans, ans2;
    DSU dsu(n);

    for (auto &road:roads) {
        int u = dsu.find(road.first), v = dsu.find(road.second);
        if (u != v) {
            dsu.merge(u, v);
        } else {
            ans.emplace_back(road.first, road.second);
        }
    }

    int root = dsu.find(0);
    for (int i = 1; i < n; ++i) {
        if (dsu.find(i) != root) {
            ans2.emplace_back(root, i);
            dsu.merge(root, i);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first+1 << " " << ans[i].second+1 << " " << ans2[i].first+1 <<
             " " << ans2[i].second+1;
        cout << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}