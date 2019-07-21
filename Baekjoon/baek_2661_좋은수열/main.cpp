#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> s;

bool isBad() {
    int size=s.size()/2;
    for(int i=2; i<=size; ++i) {
        bool flag=true;
        for(int j=0; j<i; ++j) {
            if(s[s.size()-i+j]!=s[s.size()-2*i+j]) {
                flag = false;
                break;
            }
        }
        if(flag)
            return true;
    }
    return false;
}

void solve(int n) {
    if(isBad())
        return;
    if(n==N) {
        for(auto &c:s) {
            cout<<c;
        }
        exit(0);
    }
    for(int i=1; i<=3; ++i) {
        if(s.back()!=i) {
            s.emplace_back(i);
            solve(n+1);
            s.pop_back();
        }
    }
}
int main() {
    cin>>N;
    s.emplace_back(1);
    solve(1);
    return 0;

}