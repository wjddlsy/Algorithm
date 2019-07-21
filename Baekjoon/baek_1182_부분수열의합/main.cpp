#include <iostream>
#include <vector>

using namespace std;
int N, S, ret;
vector<int> perm;

void solve(int pos, int sum) {
    if(pos==N) {
        if(sum==S)
            ret++;
        return;
    }
    solve(pos+1, sum+perm[pos]);
    solve(pos+1, sum);
}

int main() {
    cin>>N>>S;
    perm.resize(N);
    for(auto &p:perm){
        cin>>p;
    }
    solve(0, 0);
    if(S==0) ret--;
    cout<<ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}