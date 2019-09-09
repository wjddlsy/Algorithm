#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

int main() {
    int n;
    cin>>n;
    list<int> ls;
    for(int i=0; i<n; ++i) {
        int key; cin>>key;
        auto it = prev(ls.end(), key);
        ls.insert(it, i+1);
    }
    for(auto &key:ls) {
        cout<<key<<" ";
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}