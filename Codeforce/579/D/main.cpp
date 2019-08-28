#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin>>s>>t;
    int found1=s.find(t);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int found2=s.find(t);

    int ret1=max(found1, (int)s.size()-(found1+(int)t.size()));
    int ret2=max(found2, (int)s.size()-(found2+(int)t.size()));
    cout<<max(ret1, ret2);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}