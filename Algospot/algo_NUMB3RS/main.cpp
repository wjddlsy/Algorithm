#include <iostream>

using namespace std;

int A[50][50];
int main() {
    int c;
    cin>>c;
    while(c--){
        int n, d, p;
        cin>>n>>d>>p;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cin>>A[i][j];
        }

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}