#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> perm(n+1);
    vector<int> pos(n+1);
    for (int i=1; i<=n; ++i) {
        cin>>perm[i];
        pos[perm[i]]=i;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}