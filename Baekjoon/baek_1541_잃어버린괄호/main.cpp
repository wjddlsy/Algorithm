#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    string num;
    int ret = 0;

    bool first = true;
    int pos = 1000;
    vector<int> nums;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        //int minus = false;
        int mid = 0;
        if (s[i] == '-') {
            int n = stoi(num);
            num = "";
            nums.emplace_back(n);
            if (first) {
                pos = cnt;
                first = false;
            }
            cnt++;
            //minus = true;
        } else if (s[i] == '+') {
            int n = stoi(num);
            num = "";
            nums.emplace_back(n);
            cnt++;
        } else {
            num += s[i];
        }
    }

    int n = stoi(num);
    nums.emplace_back(n);
    cnt++;

    for (int i = 0; i < cnt; ++i) {
        if (i <= pos)
            ret += nums[i];
        else
            ret -= nums[i];
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
