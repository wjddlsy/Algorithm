#include <iostream>
#include "stack"
using namespace std;

int main() {
    stack<char> stk;
    string s;
    cin>>s;
    int sum=0;
    auto it=s.begin();
    while(it!=s.end()){
        if(*it=='(' && *(it+1)==')'){
            it++;
            sum+=stk.size();
        }
        else if(*it=='('){
            stk.push(*it);
        }
        else if(*it==')'){
            stk.pop();
            sum++;
        }

        it++;
    }
    cout << sum;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}