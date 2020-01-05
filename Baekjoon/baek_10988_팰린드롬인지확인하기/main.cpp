#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();


    for(int i=0; i<n/2; ++i) {
        if(s[i] != s[n-i-1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
