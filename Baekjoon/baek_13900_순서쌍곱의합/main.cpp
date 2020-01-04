#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long ans = 0;
    long long sum = 0;
    vector<int> nums(N);

    for(auto &num:nums) {
        cin >> num;
        sum += num;
    }

    for(auto &num:nums) {
        sum -= num;
        ans += sum * num;
    }

    cout << ans;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}