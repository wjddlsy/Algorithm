#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool decision(vector<int>& lessons, int length) {
    int n=0;
    for(int i=0; i<N; ){
        int sum=0;
        if(lessons[i]>length)
            return false;
        while(i<N && sum+lessons[i]<=length) {
            sum+=lessons[i];
            i++;
        }
        n++;
    }
    return n<=M;
}

int optimize(vector<int>& lessons) {
    int lo=-1, hi=1000000000;
    while(lo+1<hi) {
        int mid=(lo+hi)/2;
        if(decision(lessons, mid))
            hi=mid;
        else
            lo=mid;
    }
    return hi;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    vector<int> lessons(N);
    for(auto &lesson:lessons) {
        cin>>lesson;
    }
    cout<<optimize(lessons);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}