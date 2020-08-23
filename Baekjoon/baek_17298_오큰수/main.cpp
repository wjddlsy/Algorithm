#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> A(N);

    for(auto &a:A) {
        cin >> a;
    }

    deque<int> sorted;
    vector<int> ans(N);

    for(int i=N-1; i>=0; --i) {
        const int n = A[i];
        while(!sorted.empty() && sorted.front() <= n) {
            sorted.pop_front();
        }
        ans[i] = sorted.empty() ? -1 : sorted.front();
        sorted.push_front(n);
    }

    for(auto &a:ans) {
        cout << a << " ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
