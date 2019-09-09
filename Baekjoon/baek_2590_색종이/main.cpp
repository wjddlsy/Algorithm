#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int ret = 0;
    int count[7];
    for (int i = 1; i <= 6; ++i) {
        cin >> count[i];
    }
    ret += count[6];
    while (count[5] > 0) {
        ret++;
        count[5]--;
        count[1] -= 11;
    }
    while (count[4] > 0) {
        ret++;
        count[4]--;
        if (count[2] >= 5) count[2] -= 5;
        else {
            count[1] -= (5 - count[2]) * 4;
            count[2] = 0;
        }
    }
    while (count[3] > 0) {
        ret++;
        if (count[3] >= 4)
            count[3] -= 4;
        else {
            int minus = 0;
            if (count[3] == 3) {
                minus = min(1, count[2]) * 4;
                count[2] -= 1;
            } else if (count[3] == 2) {
                minus = min(3, count[2]) * 4;
                count[2] -= 3;
            } else if (count[3] == 1) {
                minus = min(5, count[2]) * 4;
                count[2] -= 5;
            }
            count[1] -= 36 - count[3] * 9 - minus;
            count[3] = 0;
        }
    }
    while (count[2] > 0) {
        ret++;
        if (count[2] >= 9)
            count[2] -= 9;
        else {
            count[1] -= (36 - count[2] * 4);
            count[2] = 0;
        }
    }

    if(count[1]>0) {
        ret += (count[1] % 36 == 0 ? count[1] / 36 : count[1] / 36 + 1);
    }

    cout << ret;
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}