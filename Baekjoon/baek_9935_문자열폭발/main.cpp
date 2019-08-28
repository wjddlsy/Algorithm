#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Stack {
    int top=0;
    string pattern;
    char arr[1000001];

    Stack(string pattern):pattern(std::move(pattern)) {
    }

    bool add(char c) {
        arr[top++]=c;
        if(top<pattern.size())
            return false;
        for(int i=0; i<pattern.size(); ++i) {
            if(arr[top-i-1]!=pattern[i])
                return false;
        }
        top-=pattern.size();
        return true;
    }
};
int main() {
    string s, t;
    cin>>s>>t;

    reverse(t.begin(), t.end());
    Stack stack(t);

    int l=0;
    while(l<s.size()) {
        stack.add(s[l++]);
    }

    if(!stack.top)
        cout<<"FRULA";
    else {
        for(int i=0; i<stack.top; ++i) {
            cout<<stack.arr[i];
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}