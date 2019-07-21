#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, ret=0, sum=0;
    cin>>n>>m;
    vector<int> perm(n);
    for(int left=0, right=0; right<n; ++right) {
        cin>>perm[right];
        sum+=perm[right];
        while(sum>m) sum-=perm[left++];
        if(sum==m) ret++;
    }
    cout<<ret;
    return 0;
}