#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
int height[300001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    long long C=0;
    cin>>N;
    map<int, int> m;
    m.insert({-333333,0}); m.insert({600001, 0});
    for(int i=0; i<N; ++i){
        int a;
        cin>>a;
        if(i==0){
            m.insert({a,0});
        }
        else {
            auto it=m.lower_bound(a);
            auto it2=it;
            it--;
            int val=(it2->second>it->second?it2->second:it->second);
            m.insert({a,val+1});
            C+=(val+1);
        }
        cout<<C<<'\n';
    }
    return 0;
}