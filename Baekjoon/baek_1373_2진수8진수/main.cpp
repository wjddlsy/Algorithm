#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string binary, ret;
    cin>>binary;
    reverse(binary.begin(), binary.end());
    for(int i=0; i<binary.size(); i+=3) {
        int digit=0;
        for(int j=0; j<3; ++j) {
            if(i+j>=binary.size())
                break;
            digit+=((int)pow(2, j)*(binary[i+j]-'0'));
        }
        ret+=(digit+'0');
    }
    reverse(ret.begin(), ret.end());
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}