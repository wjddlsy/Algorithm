#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos;
int c, l, k;

// 가장 긴 조각이 h 이하로 자를 수 있는가
bool decision(int h) {
    int cut=0, sum=0;
    for(int i=1; i<pos.size(); ++i) {
        if(pos[i]-pos[i-1]>h)
            return false;
        if(sum+pos[i]-pos[i-1]>h) {
            cut++;
            sum=pos[i]-pos[i-1];
        } else {
            sum+=pos[i]-pos[i-1];
        }
    }
    return cut<=c;
}

int optimize() {
    long long lo=0, hi=l;
    while(lo+1<hi) {
        long long mid=(lo+hi)/2;
        if(decision(mid))
            hi=mid;
        else
            lo=mid;
    }
    return hi;
}
int main() {
    cin >> l >> k >> c;
    pos.resize(k+1, 0);
    for (int i = 1; i <=k; ++i) {
        cin>>pos[i];
    }
    pos.emplace_back(l);
    sort(pos.begin(), pos.end());

    int ret=optimize(), index=k, sum=0;
    for(int i=pos.size()-1; i>0; --i) {
        if(sum+pos[i]-pos[i-1]>ret) {
            sum=pos[i]-pos[i-1];
            c--;
            index=i;
        } else {
            sum+=pos[i]-pos[i-1];
        }
    }
    if(c>0) index=1;
    cout<<ret<<" "<<pos[index];
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
