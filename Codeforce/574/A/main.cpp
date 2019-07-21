#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> drink(k+1, 0);
    for(int i=0; i<n; ++i) {
        int t; cin>>t;
        drink[t]++;
    }
    int ret=0;
    bool tmp=false;
    sort(drink.begin(), drink.end());
    for(int i=1; i<=k; ++i) {
        if(drink[i]%2==0) {
            ret+=drink[i];
        } else {
            if(!tmp) {
                ret+=drink[i];
                tmp=true;
            } else {
               ret+=drink[i]-1;
               tmp=false;
            }
        }
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}