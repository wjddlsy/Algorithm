#include <iostream>
#include <vector>

using namespace std;

int function(int n) {
    return n*(n+1)/2;
}

int main() {
    int N;
    cin>>N;
    int left=1, right=1;
    long long sum=0;
    int ret=1;
    for(;left<=N; ++left) {
        if(sum==N)
            ret++;
        while(right<N && sum<N) {
            sum+=right;
            if(sum==N)
                ret++;
            right++;
        }
        sum-=left;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}