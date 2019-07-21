#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int N, K, x1, y1, C, D, E1, E2, F;
        cin>>N>>K>>x1>>y1>>C>>D>>E1>>E2>>F;
        vector<int> A(N+1, 0);
        for(int i=1; i<=N; ++i){
            A[i]=(x1+y1)%F;
            x1=(C*x1+D*y1+E1)%F;
            y1=(D*x1+C*y1+E2)%F;
        }

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}