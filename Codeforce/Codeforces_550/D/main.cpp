#include <iostream>
#include <vector>

using namespace std;

int cnt[200001];
int main() {
    int n;
    cin>>n;
    vector<long long> arr;
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        arr.push_back(a);
        cnt[a]++;
    }
    int m=0, cm=0;
    for(int i=0; i<=200000; ++i){
        if(cnt[i]>cm){
            cm=cnt[i];
            m=i;
        }
    }
    int pos=0;
    for(int i=0; i<n; ++i){
        if(arr[i]==m){
            pos=i;
            break;
        }
    }

    bool flag=true;
    cout<<n-cm<<'\n';
    for(int i=pos; i>=0; --i){
        if(arr[i]!=m){
            flag=false;
            if(arr[i]<m){
                cout<<1<<" ";
            }
            else {
                cout<<2<<" ";
            }
            cout<<i+1<<" "<<i+2;
            cout<<'\n';
        }
    }

    for(int i=pos+1; i<n; ++i){
        if(arr[i]!=m){
            flag=false;
            if(arr[i]<m){
                cout<<1<<" ";
            }
            else {
                cout<<2<<" ";
            }
            cout<<i+1<<" "<<i;
            cout<<'\n';
        }
    }

    return 0;
}