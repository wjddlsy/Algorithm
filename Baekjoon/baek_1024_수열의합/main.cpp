#include <iostream>


using namespace std;

long long summ(long long a, long long b){
    // a~b까지 합
    long long b_sum= b*(b+1)/2;
    long long a_sum = a*(a+1)/2;
    return b_sum - a_sum + a;
}


int main() {
    long long N, L, ret=0, l;
    bool flag=false;
    cin>>N>>L;

    for(l=L; l<=100; ++l){
        int start = N / l - l;
        int end = N / l;
        int sum=0;

        if(start<0)
            start=0;
        for(int i=start; i<=end; ++i) {
            sum = summ(i, i + l -1 );
            if (sum == N) {
                ret = i;
                flag = true;
                break;
            }
            if(sum>N)
                break;
        }

        if(flag)
            break;
    }

    if(flag){
        for(int i=0; i<l; ++i){
            cout << ret + i << " ";
        }
    }

    else
        cout << -1;
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}