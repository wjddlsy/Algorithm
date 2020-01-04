#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a) {
    long long ret = 0;
    for (auto &item:a) {
        ret += item;
    }
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}