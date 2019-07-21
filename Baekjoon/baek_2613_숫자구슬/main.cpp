#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> ret;
bool decision(vector<int>& marbles, int k) {
    ret.clear();
    int n=0, remain=marbles.size();
    for(int i=0; i<marbles.size();) {
        int sum=0, tmp=0;
        while(i<marbles.size() && sum+marbles[i]<=k && remain+n>=M) {
            sum+=marbles[i];
            tmp++;
            --remain;
            ++i;
        }
        ret.emplace_back(tmp);
        ++n;
    }

    return n>M;
}

int optimize(vector<int>& marbles) {
    int lo=*max_element(marbles.begin(), marbles.end()), hi=30000;
    while(lo<hi) {
        int mid=(lo+hi)/2;
        if(decision(marbles, mid)) {
            lo=mid+1;
        } else {
            hi=mid;
        }
    }
    return lo;
}

int main() {
    cin>>N>>M;

    vector<int> marbles(N);
    for(auto &marble:marbles) {
        cin>>marble;
    }

    ret.clear();
    int ans=optimize(marbles);
    decision(marbles, ans);
    cout<<ans<<'\n';
    for(auto &r:ret){
        cout<<r<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}