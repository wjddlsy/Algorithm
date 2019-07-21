#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long n;
    cin>>n;
    vector<long long> length(n);
    long long maxValue=0, sum=0;
    for(int i=0; i<n; ++i){
        cin>>length[i];
        maxValue=max(maxValue, length[i]);
        sum+=length[i];
    }
    long long c=maxValue, a=sum-maxValue;
    long long b=c-a+1;
    cout<<b;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}