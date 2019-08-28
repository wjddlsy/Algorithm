#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &a:arr) {
            cin>>a;
        }
        long long ret=0;
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                ret+=gcd(arr[i], arr[j]);
            }
        }
        cout<<ret<<'\n';

    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}