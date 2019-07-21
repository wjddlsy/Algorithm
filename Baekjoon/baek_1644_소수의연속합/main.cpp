#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime;

void eratos(int n) {
    isPrime=vector<bool>(n+1, true);
    for(int i=2; i*i<=n; ++i){
        if(isPrime[i]) {
            for(int j=i*2; j<=n; j+=i)
                isPrime[j]=false;
        }
    }
}

int main() {
    int N;
    cin>>N;
    eratos(N);
    int sum=0, ret=0;
    vector<int> perm;
    for(int i=2; i<=N; ++i){
        if(isPrime[i])
            perm.emplace_back(i);
    }
    for(int left=0, right=0; right<perm.size(); ++right) {
        sum+=perm[right];
        while(sum>N) {
            sum-=perm[left++];
        }
        if(sum==N)
            ret++;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}