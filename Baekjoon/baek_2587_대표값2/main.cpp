#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> arr(5);
    int sum=0;
    for(auto &n:arr) {
        cin>>n;
        sum+=n;
    }
    sort(arr.begin(), arr.end());
    cout<<sum/5<<'\n'<<arr[2];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}