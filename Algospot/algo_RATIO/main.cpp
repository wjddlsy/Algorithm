#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        long long N, M;
        cin>>N>>M;

        long long toBe=(M*100ll/N)+1;
        if(toBe==100ll) {
            cout << -1 << '\n';
            continue;
        }

        long long ret=((toBe*N-100ll*M)/(100ll-toBe))+((toBe*N-100ll*M)%(100ll-toBe)!=0);

        if(ret<0)
            cout<<-1<<'\n';
        else {
            cout << ret << '\n';
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}