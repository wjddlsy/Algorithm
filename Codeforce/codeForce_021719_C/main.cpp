#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=1; i<=n; ++i){
        int in;
        cin>>in;
        a.push_back(in);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}