#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_permutation(vector<int>::iterator first, vector<int>::iterator last){
    if(first==last) return false;
    auto i = last;
    if(first == --i) return false;
    while(true) {
        vector<int>::iterator i1, i2;
        i1=i;
        if(*--i < *i1) {
            i2=last;
            while(!(*i<*--i2))
                ;
            iter_swap(i, i2);
            reverse(i1, last);
            return true;
        }
        if(i==first){
            reverse(first, last);
            return false;
        }
    }
}
int main() {
    int N;
    cin>>N;
    vector<int> perm(N), next(N);
    for(auto &p:perm){
        cin>>p;
    }
    bool ret=next_permutation(perm.begin(), perm.end());
    if(!ret)
        cout<<-1;
    else {
        for (auto &p:perm) {
            cout << p << " ";
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}