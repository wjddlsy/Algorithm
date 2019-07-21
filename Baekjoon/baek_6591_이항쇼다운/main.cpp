#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while(true){
        cin>>n>>k;
        if(n==0 && k==0)
            break;
        long long ret=1;
        k=min(k, n-k);
        for(int i=1; i<=k; ++i){
            ret*=n;
            ret/=i;
            n--;
        }
        cout<<ret<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}