#include <iostream>
#include <vector>

using namespace std;
const int INF=987654321;
int main() {
    int n, m, size=INF;
    cin>>n>>m;
    vector<int> perm(n+1,0);
    for(int left=0, right=1; right<=n; ++right) {
        cin>>perm[right];
        perm[right]+=perm[right-1];
        while(perm[right]-perm[left]>=m) {
            size=min(size, right-left);
            left++;
        }
    }

    cout<<(size==INF?0:size);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}