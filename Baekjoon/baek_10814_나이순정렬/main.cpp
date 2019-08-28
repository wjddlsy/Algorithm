#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<tuple<int, int, string>> members(N);
    for(int i=0; i<N; ++i) {
        int year; string name;
        cin>>year>>name;
        members[i]={year, i, name};
    }
    sort(members.begin(), members.end());
    for(auto &member:members) {
        cout<<get<0>(member)<<" "<<get<2>(member)<<'\n';
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}