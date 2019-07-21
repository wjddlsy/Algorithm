#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> in(n), post(n);
    for(auto &p:in) {
        cin>>p;
    }
    for(auto &p:post) {
        cin>>p;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}