#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[1000000];

void eratos() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i=2; i*i<=1000000; ++i) {
        if(isPrime[i]) {
            for(int j=i*2; j<=1000000; j+=i)
                isPrime[j]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    eratos();
    while(true) {
        int n;
        cin>>n;
        if(n==0)
            break;
        bool flag=false;
        for(int i=3; i<=n; i+=2) {
            if(isPrime[i] && isPrime[n-i]) {
                cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<"Goldbach's conjecture is wrong.\n";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}