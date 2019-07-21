#include <cstdio>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
#define min(a,b) (a < b ? a : b)

int n;
vvi v(26);
vi indeg(26), visit(26);

void input() {
    scanf("%d", &n);
    string pre, cur;
    char arr[15];
    scanf("%s", arr);
    pre = arr;
    
    for (auto& now : pre) visit[now - 'a'] = 1;
    
    for (int t = 1; t < n; t++) {
        scanf("%s", arr);
        cur = arr;
        for (auto& now : cur) visit[now - 'a'] = 1;
        int Min = min(pre.size(), cur.size());
        for (int i = 0; i < Min; i++) {
            if (pre[i] == cur[i]) continue;
            v[pre[i] - 'a'].push_back(cur[i] - 'a');
            indeg[cur[i] - 'a']++;
            break;
        }
        pre = cur;
    }
}

string solve() {
    queue <int> q;
    string ans;
    int size = 0, chk = 0;
    for (int i = 0; i < 26; i++) {
        if (!visit[i]) continue;
        if (!indeg[i]) q.push(i);
        size++;
    }
    while (!q.empty()) {
        if (q.size() > 1) chk = 1;
        int now = q.front(); q.pop();
        ans += (now + 'a');
        for (auto& next : v[now]) {
            if (!(--indeg[next]))
                q.push(next);
        }
    }
    if (ans.size() < size) return "!";
    if (chk) return "?";
    return ans;
}

int main() {
    input();
    printf("%s\n", solve().c_str());
    return 0;
}
