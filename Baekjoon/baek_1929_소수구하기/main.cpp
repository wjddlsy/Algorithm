#include <iostream>
#include <string.h>
using namespace std;

bool arr[1000001]={true, };

void Eratos(int n){
    if(n<=1) return;
    memset(arr, true, sizeof(arr));
    arr[1]=false;
    for(int i=2; i*i<=n; ++i){
        if(arr[i]){
            for(int j=i*i; j<=n; j+=i){
                arr[j]=false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int m,n;
    cin>>m>>n;
    Eratos(n);
    for(int i=m; i<=n; ++i){
        if(arr[i])
            cout << i << '\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}