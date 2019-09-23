#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &a:arr) {
        cin>>a;
    }
    deque<int> lis;
    for (int i = 0; i < n; ++i) {
        if(lis.empty())
            lis.push_back(arr[i]);
        else if (lis.front() < arr[i])
            lis.push_front(arr[i]);
        else if (lis.back() > arr[i])
            lis.push_back(arr[i]);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i], greater<>());
            *it = arr[i];
        }
    }
    cout << lis.size() ;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}