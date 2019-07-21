#include <iostream>
#include <vector>

using namespace std;
int N;
void makePermutation(int size, vector<int>& perm, int status) {
    if(size==0) {
        for(auto &p:perm){
            cout<<p<<" ";
        }
        cout<<'\n';
    }
    for(int i=1; i<=N; ++i){
        if(status & (1<<i)) {
            continue;
        }
        perm.emplace_back(i);
        makePermutation(size-1, perm, status|(1<<i));
        perm.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    vector<int> perm;
    makePermutation(N, perm, 0);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}