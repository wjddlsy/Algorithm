#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> input;
    int sum=0;
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        sum+=a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    int multiple=input[0];
    // 누구를 나눌까
    int ret=sum;
    for(int i=0; i<n; ++i){
        for(int j=2; j<=input[i]; ++j){
            int sub, plus;
            if(input[i]%j==0){
                sub=input[i]-input[i]/j;
                plus=multiple*j-multiple;
                if(plus-sub<0){
                    ret=min(ret, sum+plus-sub);
                }
            }
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}