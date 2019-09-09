#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 작은 숫자가 큰 숫자 왼쪽에 오는 경우
// IV, IX,  / XL, XC, CD, CM

map<char, int> m{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};

int convert(const string &a) {
    int ret = 0, minV = 2000;
    for (auto c:a) {
        if (m[c] > minV) {
            ret = ret - 2 * minV;
        }
        minV = m[c];
        ret += m[c];
    }
    return ret;
}

string reverse(int a) {
    string ret;
    while (a) {
        if (a >= 1000) {
            for (int i = 0; i < a / 1000; ++i) {
                ret += 'M';
            }
            a %= 1000;
        } else if (a >= 900) {
            a -= 900;
            ret += "CM";
        } else if (a >= 500) {
            a -= 500;
            ret += 'D';
        } else if (a >= 400) {
            a -= 400;
            ret += "CD";

        } else if (a >= 100) {
            for (int i = 0; i < a / 100; ++i) {
                ret += 'C';
            }
            a %= 100;
        } else if (a >= 90) {
            a -= 90;
            ret += "XC";
        } else if (a >= 50) {
            a -= 50;
            ret += 'L';
        } else if (a >= 40) {
            a -= 40;
            ret += "XL";
        } else if (a >= 10) {
            for (int i = 0; i < a / 10; ++i) {
                ret += 'X';
            }
            a %= 10;
        } else if (a >= 9) {
            a -= 9;
            ret += "IX";
        } else if (a >= 5) {
            a -= 5;
            ret += 'V';
        } else if (a >= 4) {
            a -= 4;
            ret += "IV";
        } else {
            for (int i = 0; i < a; ++i) {
                ret += 'I';
            }
            a %= 1;
        }
    }
    return ret;
}

int main() {
    string a, b;
    cin >> a >> b;
    int na = convert(a), nb = convert(b);
    cout<<na+nb<<'\n'<<reverse(na+nb);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}