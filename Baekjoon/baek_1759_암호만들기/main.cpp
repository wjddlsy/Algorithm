#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> list;
void pick(int n, vector<int> &picked, int toPick) {
    if(toPick==0) {
        int a=0, b=0;
        for(auto &c:picked) {
            if(list[c]=='a' || list[c]=='e' || list[c]=='u' || list[c]=='i' || list[c]=='o')
                a++;
            else
                b++;
        }
        if(a>0 && b>1) {
            for(auto &c:picked){
                cout<<list[c];
            }
            cout<<'\n';
        }
    }
    int smallest=picked.empty()?0:picked.back()+1;
    for(int i=smallest; i<n; ++i){
        picked.push_back(i);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }
}
int main() {
    int L, C;
    cin>>L>>C;
    list.resize(C);
    for(auto &c:list){
        cin>>c;
    }
    sort(list.begin(), list.end());
    vector<int> picked;
    pick(C, picked, L);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}