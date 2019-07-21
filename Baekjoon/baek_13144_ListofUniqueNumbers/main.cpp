#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> perm(n);
    for(auto &p:perm){
        cin>>p;
    }
    bool isUsed[100001]={};
    int cur=0, prev=0, left=0;
    long long ret=0;
    for(int right=0; right<n; ++right ){
         while(isUsed[perm[right]]) {
             isUsed[perm[left]]=false;
             left++;
             prev--;
         }
         isUsed[perm[right]]=true;
         cur=prev+1;
         prev=cur;
         ret+=cur;
    }
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}