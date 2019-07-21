#include <iostream>
#include <vector>

using namespace std;

int main() {
    string A, B;
    cin>>A>>B;
    int minV=1e9;
    for(int i=0; i<=B.size()-A.size(); ++i) {
        int sum=0;
        for(int j=0; j<A.size(); ++j) {
            sum+=(A[j]!=B[i+j]);
        }
        minV=min(minV, sum);
    }
    cout<<minV;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}