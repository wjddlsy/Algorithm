#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        string ret;
        ret = ret + s[0] + s[s.length() -1];
        cout << ret << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
