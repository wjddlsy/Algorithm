#include <iostream>
#include <cstring>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> arr(N);
    vector<int> lis(N, 0), lds(N, 0);
    for (auto &a:arr) {
        cin >> a;
    }
    for(int i=N-1; i>=0; --i) {
        lis[i] = lds[i] = 1;
        for(int j=i+1; j<N; ++j) {
            if(arr[i] > arr[j])
                lds[i] = max(lds[i], lds[j] + 1);
            if(arr[i] < arr[j])
                lis[i] = max(lis[i], lis[j]+1);
        }
    }
    int ret = 0;
    for(int i=0; i<N; ++i) {
        ret = max(ret, lis[i] + lds[i] - 1);
    }
    cout<< ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}