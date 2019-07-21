#include <iostream>

using namespace std;

int kids[1000001];
int pos[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>kids[i];
        pos[kids[i]]=i;
    }
    int ret=0;
    for(int i=1; i<n; ++i) {
        int cur=i;
        int next=pos[kids[cur]+1];
        int len=1;
        while(cur<next) {
            cur=next;
            next=pos[kids[cur]+1];
            len++;
        }
        ret=max(ret, len);
    }
    cout<<n-ret;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}