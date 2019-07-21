#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[200001];
int main() {
    int n;
    cin>>n;
    vector<int> arr;
    vector<int> two;
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        cnt[a]++;
        if(cnt[a]>2){
            cout<<"NO";
            return 0;
        }
        if(cnt[a]==2){
            two.push_back(a);
        }
        else
            arr.push_back(a);
    }

    sort(two.begin(), two.end());
    sort(arr.begin(), arr.end());
    cout<<"YES"<<'\n';
    cout<<arr.size()<<'\n';
    for(int i=0; i<arr.size(); ++i){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
    cout<<two.size()<<'\n';
    for(int i=two.size()-1; i>=0; --i){
        cout<<two[i]<<" ";
    }
    cout<<'\n';
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}