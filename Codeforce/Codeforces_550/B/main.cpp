#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> odd, even;
    int sum=0;
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        sum+=a;
        if(a%2==1)
            odd.push_back(a);
        else
            even.push_back(a);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    vector<int> teven, todd;
    teven=even; todd=odd;
    bool flag=true;
    int ret=0;
    while(true){
        if(flag){
            if(todd.empty())
                break;
            ret+=todd.back();
            todd.pop_back();
        }
        else {
            if(teven.empty())
                break;
            ret+=teven.back();
            teven.pop_back();
        }
        flag=!flag;
    }

    teven=even; todd=odd;
    flag=false;
    int ret2=0;
    while(true){
        if(flag){
            if(todd.empty())
                break;
            ret2+=todd.back();
            todd.pop_back();
        }
        else {
            if(teven.empty())
                break;
            ret2+=teven.back();
            teven.pop_back();
        }
        flag=!flag;
    }

    cout<<sum-max(ret, ret2);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}