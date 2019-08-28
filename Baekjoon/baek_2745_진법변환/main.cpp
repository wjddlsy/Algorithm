#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string N;
    int B, ret=0;
    cin>>N>>B;
    for(int i=0; i<N.size(); ++i) {
        int n=isalpha(N[i])?N[i]-'A'+10:N[i]-'0';
        ret+=(int)pow(B, N.size()-1-i)*n;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}