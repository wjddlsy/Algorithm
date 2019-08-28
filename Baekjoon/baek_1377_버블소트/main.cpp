#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; ++i) {
        int a; cin>>a;
        arr[i]={a, i};
    }
    sort(arr.begin(), arr.end());

    int ret=0;
    for(int i=0; i<n; ++i) {
        ret=max(ret, arr[i].second-i);
    }

    cout<<ret+1;
    // 도대체 언제 이 버블 소트가 끝나는지
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}