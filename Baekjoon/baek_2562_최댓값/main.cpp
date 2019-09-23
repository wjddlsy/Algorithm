#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr(9);
    for(auto &a:arr) {
        cin>>a;
    }

    auto it = max_element(arr.begin(), arr.end());
    cout<<*it<<'\n'<<distance(arr.begin(), it)+1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}