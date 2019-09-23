#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[1000001];
int cache[1000001];

const int INF = 987654321;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    for(int i=0; i<N; ++i) {
        cin>>arr[i];
    }
    memset(cache, 1, sizeof(cache));
    // 일반적인 풀이법
    for(int i=0; i<N; ++i) {
        // 이 부분을 log 시간으로 줄여줘야한다.
        for(int j=0; j<i; ++j) {
            if(arr[i] > arr[j])
                cache[i] = max(cache[i], cache[j]+1);
        }
    }
    vector<int> lis{-INF};
    for(int i=0; i<N; ++i) {
        if (lis.back() < arr[i]) {
            lis.emplace_back(arr[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << lis.size() -1 ;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}