#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool decision(vector<int>& trees, int h) {
    long long sum=0;
    for(auto &tree:trees) {
        if(tree<=h)
            break;
        sum+=tree-h;
    }
    return sum>=M;
}

long long optimize(vector<int>& trees) {
    long long lo=-1, hi=trees[0];
    while(lo+1<hi) {
        long long mid=(lo+hi)/2;
        bool canGet=decision(trees, mid);
        if(canGet)
            lo=mid;
        else
            hi=mid;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    vector<int> trees(N);
    for(auto &tree:trees) {
        cin>>tree;
    }

    sort(trees.begin(), trees.end(), greater<>());

    cout<<optimize(trees);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}