#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string octa, ret;
    cin>>octa;
    if(octa=="0") {
        cout<<0;
        return 0;
    }
    for(int i=0; i<octa.size(); ++i) {
        int digit=octa[i]-'0';
        string bi;
        while(digit) {
            bi+=(digit%2+'0');
            digit/=2;
        }
        reverse(bi.begin(), bi.end());
        if(i!=0 && bi.size()<3) {
            for(int j=bi.size(); j<3; ++j) {
                ret+='0';
            }
        }
        ret+=bi;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}