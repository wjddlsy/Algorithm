#include <iostream>
#include <cmath>
using namespace std;

bool isSquare[1000001];
int main() {
    long long minValue, maxValue;
    cin>>minValue>>maxValue;
    int ret=0;
    for(long long i=2; i*i<=maxValue; ++i) {
        long long square=i*i;
        for(long long j=((minValue-1)/square+1)*square; j<=maxValue; j+=square) {
            isSquare[j-minValue]=true;
        }
    }
    for(long long i=minValue; i<=maxValue; ++i) {
        if(!isSquare[i-minValue])
            ret++;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}