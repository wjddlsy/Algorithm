#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<long long> psum(n+1, 0);
    for(int i=1; i<=n; ++i){
        cin>>psum[i];
        psum[i]+=psum[i-1];
    }
    double sum=0;
    long long div=n-k+1;

    for(int i=1; i<=n-k+1; ++i) {
        int l=i, r=i+k-1;
        sum+=psum[r]-psum[l-1];
    }

    printf("%.10lf", sum/div);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}