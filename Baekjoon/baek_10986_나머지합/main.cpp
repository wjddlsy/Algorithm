#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>>N>>M;
    long long remain[1000]={0,};
    long long sum=0, ret=0, in;

    for(int i=0; i<N; ++i){
        cin>>in;
        sum+=in;
        remain[sum%M]++;
    }

    for(int i=0; i<M; ++i){
        ret+= ((remain[i]*(remain[i]-1))/2);
    }
    ret+=remain[0];

    cout<<ret<<'\n';
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}