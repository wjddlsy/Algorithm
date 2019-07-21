#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool decision(vector<int> &budgets, int upper) {
    int sum=0;
    for(int i=0; i<N; ++i) {
        if(upper<=budgets[i]) {
            sum+=upper*(N-i);
            break;
        }
        sum+=budgets[i];
    }
    return sum<=M;
}

int optimize(vector<int> &budgets) {
    int lo=0, hi=budgets.back()+1;
    while(lo<hi-1) {
        int mid = (lo + hi) / 2;
        if (decision(budgets, mid)) {
            lo = mid;
        } else
            hi = mid;
    }
    return lo;
}
int main() {
    cin>>N;
    vector<int> budgets(N);
    for(auto &budget:budgets){
        cin>>budget;
    }
    cin>>M;
    sort(budgets.begin(), budgets.end());
    cout<<optimize(budgets);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}