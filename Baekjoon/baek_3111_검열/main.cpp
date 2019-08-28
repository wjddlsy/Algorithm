#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


string A, T;
struct Stack {
    int top=0;
    char arr[500001];
    string word;

    void push(char c) {
        arr[top++]=c;
    }
    bool check() {
        if(top<A.size())
            return false;
        for(int i=0; i<A.size(); ++i) {
            if(arr[top-i-1] != word[i])
                return false;
        }
        top-=A.size();
        return true;
    }
};
int main() {
    cin>>A>>T;
    Stack a, b;
    b.word=A;
    reverse(A.begin(), A.end());
    a.word=A;

    int l=0, r=T.size()-1;
    bool flag=true;
    while(l<=r) {
        if(flag) {
                a.push(T[l++]);
                flag^=a.check();
        } else {
            b.push(T[r--]);
            flag^=b.check();
        }
    }
    while(a.top!=0) {
        b.push(a.arr[--a.top]);
        b.check();
    }
    while(b.top!=0) {
        cout<<b.arr[--b.top];
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}