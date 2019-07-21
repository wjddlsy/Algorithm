#include <iostream>

using namespace std;

int D[1001];
bool K[1001][1001];

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        int a, b;
        for(int i=1; i<=n; ++i){
            cin>>a;
            D[i]=a;
        }
        for(int i=0; i<k; ++i){
            cin>>a>>b;
            K[a][b]=true;
        }

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}