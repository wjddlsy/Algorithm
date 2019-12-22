#include <iostream>

using namespace std;

int freq[42];

int main() {
    for (int i=0; i<10; ++i) {
        int a; cin >> a;
        freq[a%42]++;
    }
    int ret = 0;
    for(int i=0; i<42; ++i) {
        if(freq[i])
            ret++;
    }
    cout << ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}