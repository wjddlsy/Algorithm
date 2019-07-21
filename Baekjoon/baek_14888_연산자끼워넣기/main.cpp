#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

vector<int> nums;
vector<int> ops;

int solve(){
    int ret=nums[0];
    for(int i=0; i<nums.size()-1; ++i){
        switch(ops[i]){
            case 0:
                ret+=nums[i+1];
                break;
            case 1:
                ret-=nums[i+1];
                break;
            case 2:
                ret*=nums[i+1];
                break;
            case 3:
                ret/=nums[i+1];
                break;

        }
    }

    return ret;
}
int main() {
    int n, in;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>in;
        nums.push_back(in);
    }

    for(int i=0; i<4; ++i){
        cin>>in;
        for(int j=0; j<in; ++j){
            ops.push_back(i);
        }
    }
//
//    vector<int> perm;
//    for(int i=0; i<n-1; ++i){
//        perm.push_back(i);
//    }

    int min=987654321, max=-987654321;
    do {
        int ret=solve();
        min=std::min(min, ret);
        max=std::max(max, ret);
    } while(next_permutation(ops.begin(), ops.end()));

    cout << max << '\n'<<min;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}