#include <vector>
#include <iostream>

using  namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    long long sum=0;
    for(int &x:a){
        cin>>x;
        sum+=x;
    }
    if(sum!=0){
        cout<<"YES"<<'\n';
        cout<<1<<'\n';
        cout<<1<<" "<<n<<'\n';
        return 0;
    }
    sum = 0;
    for(int i=0; i<n; ++i){
        sum+=a[i];
        if(sum!=0) {
            cout<<"YES"<<'\n';
            cout<<"2"<<'\n';
            cout<<1<<" "<<i+1<<'\n';
            cout<<i+2<<" "<<n<<'\n';

        }
    }
}