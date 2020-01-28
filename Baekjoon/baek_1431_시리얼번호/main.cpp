#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> nums(N);
    for (auto &num:nums) {
        cin >> num;
    }

    sort(nums.begin(), nums.end(),
         [](string &a, string &b) {
            if(a.length() < b.length())
                return true;
            if(a.length() > b.length())
                return false;
            int sumA = 0, sumB = 0;
            for(auto &c:a) {
                if(c >= '1' && c<='9')
                    sumA += c-'0';
            }
            for(auto &c:b) {
                if(c>='1' && c<='9')
                    sumB += c-'0';
            }
            if(sumA == sumB)
                return a < b;
            return sumA < sumB;
         }
    );

    for(auto &num:nums) {
        cout << num << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
