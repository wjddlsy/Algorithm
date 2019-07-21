#include <iostream>
#include <queue>
#include "vector"
using namespace std;
int main() {

    vector<int> r;
    int n, m;
    cin >> n>>m;

    vector<int> v;
    for(int i=1; i<=n; ++i){
        v.push_back(i);
    }

    auto idx=v.begin()+m-1;
    while(n>0){
        r.push_back(*idx);
        idx=v.erase(idx); // erase가 지운 원소 다음의 원소를 반환함
        if(idx==v.end()) idx=v.begin();
        --n;
        for(int i=0; i<m-1; ++i){
            ++idx;
            if(idx==v.end()) idx=v.begin();
        }
    }

    cout<< "<" <<r[0];
    for(int i=1; i<r.size(); ++i){
        cout<<", "<<r[i];
    }
    cout<<">";

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}