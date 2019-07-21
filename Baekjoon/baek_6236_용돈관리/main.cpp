#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool decision(vector<int>& days, int k) {
    int n=0;
    for(int i=0; i<N;){
        int sum=0;
        if(days[i]>k)
            return false;
        while(i<N && sum+days[i]<=k) {
            sum+=days[i];
            ++i;
        }
        ++n;
    }
    return n<=M;
}
int optimize(vector<int>& days) {
    int lo=-1, hi=100000000;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(decision(days, mid))
            hi=mid;
        else
            lo=mid;
    }
    return hi;
}
int main() {
    cin>>N>>M;
    vector<int> days(N);
    for(auto &day:days){
        cin>>day;
    }
    cout<<optimize(days);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}